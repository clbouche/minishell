/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:02 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/28 13:29:48 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Verifie le type de redirections dont il s'agit 
** pour envoyer a la bonne fonction.
*/
void	manage_redir(char *input, int i, t_data *data)
{	
	if (input[i] == '>' && input[i + 1] != '>')
		redir_ouput(&input[i + 1], data);
	else if (input[i] == '>' && input[i + 1] == '>')
		redir_output_append(&input[i + 2], data);
	else if (input[i] == '<' && input[i + 1] != '<')
		redir_input(input, data);
	else if (input[i] == '<' && input[i + 1] == '<')
		redir_read_input(&input[i + 2], data);
	input[i] = '\0';
}

/*
** Check le type de $ dont il s'agit
*/
char	*manage_expand(char *line, t_data *data)
{
	int		i;
	char	*new_line;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'')
			return (line);
		if (line[i] == '$')
		{
			if (line[i + 1] == '?')
				return (line);
			else if (line[i + 1] && check_char_begin(line[i + 1]))
			{
				new_line = manage_variable(line, data);
				return (new_line);
			}
			else
				return (line);
		}
		i++;
	}
	return (line);
}

/*
** Envoie les commandes correctement a l'execution pour les pipes.
*/
void	manage_pipe(char *line, int pipe_pos, t_data *data)
{
	char	*new_input;

	new_input = ft_strdup(&line[pipe_pos + 1]);
	line[pipe_pos - 1] = '\0';
	data->pipe = true;
	return (exec_pipes(line, new_input, data));
}

/*
** Fais les memes etapes que bash : 
** - Verifie d'abord les expands pour modifier l'input en foncton. 
** - Gere les pipes.
** - S'occupe des redirections
** - Tranforme l'input rendu propre en tableau de commandes.
*/
char	**parser(char *line, t_data *data)
{
	int		i;
	char	quote;
	char	**cmd;
	char	*new_line;

	i = 0;
	while (line[i++])
	{
		if (line[i] == '$')
		{
			new_line = manage_expand(line, data);
			line = new_line;
		}
		if (line[i] == '|')
		{
			manage_pipe (line, i, data);
			data->pipe = true;
		}
		if (line[i] == '"' || line[i] == '\'')
		{
			printf("enter\n");
			quote = line[i];
			i++;
			if (check_closed_quotes(&line[i]))
			{
				printf("enter 1\n");
				if (line[i] == '$' && quote == '"')
				{
					new_line = manage_expand(line, data);
					line = new_line;
				}
				i++;
			}
		}
		if (line[i] == '>' || line[i] == '<')
			manage_redir(line, i, data);
	}
	cmd = split_cmd(line);
	return (cmd);
}
