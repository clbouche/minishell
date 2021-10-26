/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:22:28 by claclou           #+#    #+#             */
/*   Updated: 2021/10/26 11:00:08 by clbouche         ###   ########.fr       */
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
		data->std_in = open(file_name, O_RDONLY);
	//if (data->std_in < 0)
	//gerer le cas ou le file n'existe pas
	free(file_name);
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
		data->std_out = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 00700);
	free(file_name);
}

/*
** Redirige le contenu de l'information demander vers un fichier.
*/
void	redir_ouput(char *str, t_data *data)
{
	char	*file_name;

	file_name = recup_filename(str);
	if (file_name)
		data->std_out = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 00700);
	free(file_name);
}

/*
** Verifie le type de redirections dont il s'agit 
** pour envoyer a la bonne fonction.
*/
void	check_redir(char *input, int i, t_data *data)
{
	int		j;

	j = i;
	if (input[i] == '>' && input[i + 1] != '>')
		redir_ouput(&input[i + 1], data);
	else if (input[i] == '>' && input[i + 1] == '>')
		redir_output_append(&input[i + 2], data);
	else if (input[i] == '<' && input[i + 1] != '<')
		redir_input(input, data);
	else if (input[i] == '<' && input[i + 1] == '<')
		redir_read_input(&input[i + 2], data);
	input[i] = '\0';
	printf("input : %s\n", input);
	//execute_redir(input, data);
}