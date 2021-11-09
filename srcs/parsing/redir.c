/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:22:28 by claclou           #+#    #+#             */
/*   Updated: 2021/11/09 14:24:47 by claclou          ###   ########.fr       */
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
	if (file_name)
	{
		data->redir_in = true;
		data->std_in = dup(0);
		close(0);
		data->file_in = open(file_name, O_RDONLY);
		if (data->file_in == -1)
		{
			puts("file_in\n");
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
		data->file_out = open(file_name, O_CREAT | O_RDWR | O_APPEND, 0644);
		free(file_name);
		if (data->file_out < 0)
			opening_error("problem while opening append");
		dup2(data->file_out, 1);
		close(data->file_out);
	}	
}


/*
** Redirige le contenu de l'information demander vers un fichier.
*/
void	redir_ouput(char *str, t_data *data)
{
	char	*file_name;
	static int		i = 1;
	
	file_name = recup_filename(str);
	if (file_name)
	{
		data->file_out = open(file_name, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
		free(file_name);
		if (i == data->count_redir_out)
		{
			data->redir_out = true;
			data->std_out = dup(1);
			dup2(data->file_out, 1);
		}
		if (data->file_out < 0)
		{
			perror("file");
			data->count_redir_out = -1;
			data->redir_out = false;
			//je dois quitter le processus pour ne pas creer les fichiers suivants
			// et je ne dois pas afficher en sortie standard le rslt attendu 
			return ;
		}
		close(data->file_out);
		i++;
	}
}
