/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:02 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/12 15:36:53 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Check le type de $ dont il s'agit
*/
void	manage_expand(char *line, t_data *data)
{
	int		i;

	i = 0;
	if (line[i + 1])
	{
		if (line[i + 1] == '?')
			return_last_rtn(data);
		else
			manage_variable(line, data);
	}
}

/*
** Envoie les commandes correctement a l'execution.
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
	int i;
	
	i = 0;
	(void)data;
	(void)quote;
	while (line[i] != quote)
	{
		if (quote == '"' && line[i] == '$')
		{
			//est ce que ca marche "$?" ??? 
			manage_expand(line, data);
		}
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
	int	i;
	char	**cmd;

	i = 0;
	while(line[i])
	{
		if (line[i] == '"' || line[i] == '\'')
			manage_quotes(&line[i], data, line[i]);
		if (line[i] == '|')
			manage_pipe(&line[i + 1], data);
		if (line[i] == '$')
			manage_expand(&line[i], data);
		i++;
	}
	cmd = complete_parser(line, data);
	return (cmd);
}
