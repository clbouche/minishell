/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:02 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/14 15:29:39 by clbouche         ###   ########.fr       */
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
void	manage_pipe(char *line, t_data *data)
{
	char	*cpy;

	(void)data;
	cpy = ft_strdup(line);
	printf("check line : %s\n", cpy);
	//executer le debut de la ligne jusqu'au pipe
	//revenir au parser avec le reste de la ligne
}

/*
** Permet de faire les expands si double quote.
*/
void	manage_quotes(char *line, t_data *data, char quote)
{
	int	i;

	i = 0;
	(void)data;
	(void)quote;
	while (line[i] != quote)
	{
		if (quote == '"' && line[i] == '$')
			manage_expand(line, data);
		i++;
	}
}

/*
** Envoie aux dernieres fonctions avant d'obtenir un input propre.
*/
char	**complete_parser(char *line, t_data *data)
{
	char	**cmd;

	manage_redir(&line, data);
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
		if (line[i] == '"' || line[i] == '\'')
			manage_quotes(line, data, line[i]);
		if (line[i] == '|')
			manage_pipe (&line[i + 1], data);
		if (line[i] == '$')
		{
			new_line = manage_expand (line, data);
			cmd = complete_parser(new_line, data);
			return (cmd);
		}
		i++;
	}
	cmd = complete_parser(line, data);
	return (cmd);
}
