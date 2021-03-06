/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:02 by clbouche          #+#    #+#             */
/*   Updated: 2021/12/02 22:17:08 by claclou          ###   ########.fr       */
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
		redir_output(&input[i + 1], data);
	else if (input[i] == '>' && input[i + 1] == '>')
	{
		redir_output_append(&input[i + 2], data);
		input[i + 1] = ' ';
	}
	else if (input[i] == '<' && input[i + 1] != '<')
		redir_input(&input[i + 1], data);
	else if (input[i] == '<' && input[i + 1] == '<')
	{
		redir_heredoc(&input[i + 2], data);
		input[i + 1] = ' ';
	}
	input[i] = ' ';
}

/*
** Check le type de $ dont il s'agit
*/
char	*manage_expand(char *line, int i, t_data *data)
{
	int		j;
	char	*new_line;

	j = 0;
	if (line[i] == '$' && (line[i + 1] == '?' || check_char_begin(line[i + 1])))
	{
		new_line = manage_variable(line, i, data);
		line = new_line;
	}
	return (line);
}

/*
** Envoie les commandes correctement a l'execution pour les pipes.
*/
char	*manage_pipe(char *line, int pipe_pos, t_data *data)
{
	char	*new_input;

	new_input = NULL;
	if (pipe_pos > 0 && line[pipe_pos - 1] != '|' && line[pipe_pos + 1] != '|')
		new_input = ft_strdup(&line[pipe_pos + 1]);
	else
	{
		ft_putstr_fd("syntax error\n", 1);
		ft_memdel(&line);
		return (line);
	}
	line[pipe_pos] = '\0';
	return (exec_pipes(line, new_input, data));
}

int	manage_quotes(char **line, int *i, t_data *data)
{
	char	*new_line;

	if ((*line)[*i] == '"')
	{
		(*i)++;
		while ((*line)[*i] && (*line)[*i] != '"')
		{
			if ((*line)[*i] == '$' && (*line)[*i + 1] != ' ')
			{
				new_line = manage_expand((*line), *i, data);
				(*line) = new_line;
			}
			(*i)++;
		}
	}
	if ((*line)[*i] == '\'')
	{
		(*i)++;
		while ((*line)[*i] != '\'')
			(*i)++;
	}
	return (0);
}

/*
** Fais les memes etapes que bash : 
** - Verifie d'abord les expands pour modifier l'input en foncton. 
** - Gere les pipes.
** - S'occupe des redirections
** - Tranforme l'input rendu propre en tableau de commandes.
*/
int	parser(char *line, t_data *data)
{
	int		i;
	char	*new_line;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == '$' && line[i + 1] != ' ')
		{
			new_line = manage_expand(line, i, data);
			line = new_line;
		}
		if (line[i] == '|' && line[i + 1])
		{
			line = manage_pipe(line, i, data);
			i = 0;
			if (line)
				data->piped = true;
			else
				return (0);
		}
		manage_quotes(&line, &i, data);
		i++;
	}
	return (parse_to_exec(line, data));
}
