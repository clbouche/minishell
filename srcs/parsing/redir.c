/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:22:28 by claclou           #+#    #+#             */
/*   Updated: 2021/12/02 17:42:53 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	re_init_redir(t_data *data)
{
	data->redir->count_out = -1;
	data->redir->r_out = false;
	data->redir->bad_r = true;
}

/*
** Lit l'entree de la source actuelle 
** jusqu'a ce que le delimiteur soit croise. 
*/
void	redir_heredoc(char *str, t_data *data)
{
	char		*delimiter;
	pid_t		pid;
	static int	count = 1;

	delimiter = NULL;
	delimiter = define_delimiter(str);
	pipe(data->fds);
	g_sig.prog = 1;
	pid = fork();
	add_to_array(data, pid);
	if (pid == 0)
	{
		signal(SIGINT, &sig_heredoc);
		heredoc_loop(delimiter, data);
		exit(1);
	}
	waitpid(-1, &g_sig.status, 0);
	if (count == data->redir->count_heredoc)
		pipe_in(data);
	free(delimiter);
	g_sig.prog = 0;
	count++;
}

/*
** Redirige l'input.
*/
void	redir_input(char *str, t_data *data)
{
	char		*file_name;
	static int	count = 1;

	file_name = recup_filename(str);
	if (file_name)
	{
		data->file_in = open(file_name, O_RDWR);
		if (count == data->redir->count_in)
		{
			data->std_in = dup(0);
			dup2(data->file_in, 0);
		}
		if (data->file_in < 0)
		{
			perror(file_name);
			free(file_name);
			data->redir->count_in = -1;
			data->redir->r_in = false;
			data->redir->bad_r = true;
			return ;
		}
		free(file_name);
		close(data->file_in);
		count++;
	}
}

/*
** Redirige le contenu de l'information demandee vers un fichier
** sans ecraser son contenu (ajoute a la fin).
*/
void	redir_output_append(char *str, t_data *data)
{
	char		*file_name;
	static int	count = 1;

	file_name = recup_filename(str);
	if (file_name)
	{
		data->file_out = open(file_name, O_RDWR | O_CREAT
				| O_APPEND, S_IRUSR | S_IWUSR);
		if (count == data->redir->count_append)
		{
			data->std_out = dup(1);
			dup2(data->file_out, 1);
		}
		else if (data->file_out < 0)
		{
			perror(file_name);
			free(file_name);
			re_init_redir(data);
			return ;
		}
		free(file_name);
		close(data->file_out);
		count++;
	}	
}

/*
** Redirige le contenu de l'information demander vers un fichier.
*/
void	redir_output(char *str, t_data *data)
{
	char		*file_name;
	static int	count = 1;

	file_name = recup_filename(str);
	if (file_name)
	{
		data->file_out = open(file_name, O_RDWR | O_CREAT
				| O_TRUNC, S_IRUSR | S_IWUSR);
		if (count == data->redir->count_out)
		{
			data->std_out = dup(1);
			dup2(data->file_out, 1);
		}
		if (data->file_out < 0)
		{
			perror(file_name);
			free(file_name);
			re_init_redir(data);
			return ;
		}
		free(file_name);
		close(data->file_out);
		count++;
	}
}
