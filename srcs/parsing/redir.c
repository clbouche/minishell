/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:22:28 by claclou           #+#    #+#             */
/*   Updated: 2021/10/21 12:13:52 by clbouche         ###   ########.fr       */
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
	//printf("delimiter : %s\n", delimiter);
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
** Verifie si on rencontrer une redirection dans la ligne de commande.
*/
int	manage_redir(char *input, t_data *data)
{
	int		i;

	i = 0;
	while (input[i++])
	{
		if (input[i] == '>' || input[i] == '<')
		{
			check_redir(input, i, data);
			return (1);
		}
	}
	return (0);
}
