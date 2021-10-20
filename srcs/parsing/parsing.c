/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:02 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/20 10:34:28 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Check le type de $ dont il s'agit
*/
char	*manage_expand(char *line, t_data *data)
{
	int		i;
	char	*new_line;

	i = 0;
	while (line[i] != '$')
		i++;
	if (line[i + 1])
	{
		if (line[i + 1] == '?')
			return (line);
		else
		{
			new_line = manage_variable(line, data);
			return (new_line);
		}
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
	line[pipe_pos] = '\0';
	return (exec_pipes(line, new_input, data));
}

/*
** Permet de faire les expands si double quote.
*/
void	manage_quotes(char *line, char *input, t_data *data, char quote)
{
	int		i;
	//char	*new_line;

	i = 0;
	(void)data;
	(void)line;
	//printf("line : %s\n", line);
	//printf("input : %s\n", input);
	while (input[i] && input[i] != quote)
	{
		//if (input[i] == '$')
		//	i++;
		//if (quote == '"' && input[i] == '$')
		//	new_line = manage_expand(line, data);
	 	//else
			i++;
	}
}

/*
** Envoie aux dernieres fonctions avant d'obtenir un input propre.
*/
char	**complete_parser(char *line, t_data *data)
{
	char	**cmd;

	manage_redir(line, data);
	cmd = split_cmd(line);
	return (cmd);
}

/*
** Verifie les caracteres particuliers que l'on peut rencontrer.
*/
char	**parser(char *line, t_data *data)
{
	int		i;
	char	**cmd;
	char	*new_line;

	i = 0;
	while (line[i])
	{
		if ((line[i] == '"' || line[i] == '\'') && line[i + 1])
			manage_quotes(line, &line[i + 1], data, line[i]);
		if (line[i] == '|')
			manage_pipe (line, i, data);
		if (line[i] == '$')
		{
			new_line = manage_expand (line, data);
			line = new_line;
		}
		i++;
	}
	cmd = complete_parser(line, data);
	return (cmd);
}
