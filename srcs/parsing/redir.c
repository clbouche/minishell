/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:22:28 by claclou           #+#    #+#             */
/*   Updated: 2021/11/18 15:50:17 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** Lit l'entree de la source actuelle 
** jusqu'a ce que le delimiteur soit croise. 
*/
void redir_heredoc(char *str, t_data *data)
{
	char	*delimiter;
	int		pid;
	int		heredocs[2];

	delimiter = NULL;
	delimiter = define_delimiter(str);
	g_sig.heredoc = true;
	g_sig.prog = 1;
	signal(SIGQUIT, &sig_heredoc);
	pipe(heredocs);
	pid = fork();
	if (pid == 0)
	{
	 	heredoc_loop(delimiter, data, heredocs);
		close(heredocs[1]);
		exit(1);
	}
	free(delimiter);
	waitpid(-1, &g_sig.status, 0);//trouver un moyen pour stocker le retour du heredoc	
	g_sig.prog = 0;
	close(heredocs[1]);	
	// 	exit(FAILURE);
}

/*
** Redirige l'input.
*/
void	redir_input(char *str, t_data *data)
{
	char	*file_name;
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
	char	*file_name;
	static int	count = 1;
	
	file_name = recup_filename(str);
	if (file_name)
	{
		data->file_out =  open(file_name, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
		if (count == data->redir->count_append)
		{
			data->std_out = dup(1);
			dup2(data->file_out, 1);
		}
		else if (data->file_out < 0)
		{
			perror(file_name);
			free(file_name);
			data->redir->count_out = -1;
			data->redir->r_out = false;
			data->redir->bad_r = true;
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
	char	*file_name;
	static int		count = 1;
	
	file_name = recup_filename(str);
	if (file_name)
	{
		data->file_out = open(file_name, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
		if (count == data->redir->count_out)
		{
			data->std_out = dup(1);
			dup2(data->file_out, 1);
		}
		if (data->file_out < 0)
		{
			perror(file_name);
			free(file_name);
			data->redir->count_out = -1;
			data->redir->r_out = false;
			data->redir->bad_r = true;
			return ;
		}
		free(file_name);
		close(data->file_out);
		count++;
	}
}
