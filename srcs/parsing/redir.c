/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:22:28 by claclou           #+#    #+#             */
/*   Updated: 2021/10/28 16:08:15 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** Lit l'entree de la source actuelle 
** jusqu'a ce que le delimiteur soit croise. 
*/
void	redir_read_input(char *str, t_data *data)
{
	char	*delimiter;
	int		pid;
	int		heredocs[2];

	delimiter = define_delimiter(str);
	//mute le signal ctlr + 
	pipe(heredocs);
	pid = fork();
	if (pid == 0)
	{
	 	heredoc_loop(delimiter, data, heredocs);
		close(heredocs[1]);
		exit(1);
	}
	waitpid(-1, &g_sig.status, 0);
	close(heredocs[1]);
}

/*
** Redirige l'input.
*/
void	redir_input(char *str, t_data *data)
{
	char	*file_name;

	file_name = recup_filename(str);
	ft_putstr_fd(str, 1);	
	ft_putstr_fd(file_name, 1);
	if (file_name)
	{
		data->redir_in = true;
		data->std_in = dup(0);
		close(0);
		data->file_in = open(file_name, O_RDONLY);
		if (data->file_in == -1)
		{
			puts("file_in");
		}
		dup2(data->file_in, 0);
		free(file_name);
	}
	//if (data->std_in < 0)
	//gerer le cas ou le file n'existe pas
}

/*
** Redirige le contenu de l'information demandee vers un fichier
** sans ecraser son contenu (ajoute a la fin).
*/
void	redir_output_append(char *str, t_data *data)
{
	char	*file_name;

	file_name = recup_filename(str);
	if (file_name)
	{
		data->redir_out = true;
		data->std_out = dup(1);
		close(1);
		data->std_out = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 00700);
		free(file_name);
		if (data->file_out < 0)
			puts("out_file");
	}
}

/*
** Redirige le contenu de l'information demander vers un fichier.
*/
void	redir_ouput(char *str, t_data *data)
{
	char	*file_name;
	file_name = recup_filename(str);
	if (file_name)
	{
		data->redir_out = true;
		data->std_out = dup(1);
		close(1);
		data->file_out = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 00700);
		free(file_name);
		if (data->file_out < 0)
			opening_error("problem while opening");
		//dup2(data->std_out);
		//close(data->file_out);
	}	
}
