/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:02 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/15 17:07:09 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*manage_quotes(char *line, int i, int quote, t_data *data)
{
	char	*new_line;

	while(line[i] != quote)
	{
		if (line[i] == '$' && quote == '"')
		{
			new_line = manage_expand(line, data);
			line = new_line;
		}
		i++;
	}
	return (line);
}

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
char	*manage_expand(char *line, t_data *data)
{
	int		i;
	char	*new_line;

	i = 0;
	while (line[i])
	{
		//if (line[i] == '\'')
		//	return (line);
		// nul comme condition, il faut verifier si l'expand est ENTRE les simples quotes.
		if (line[i] == '$' && (line[i + 1] == '?' || check_char_begin(line[i + 1])))
		{
			new_line = manage_variable(line, data);
			free(line);
			line = new_line;
		}
		i++;
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
	if (line[pipe_pos - 1] && line[pipe_pos + 1] != '|')
		new_input = ft_strdup(&line[pipe_pos + 1]);
	else
	{
		ft_putstr_fd("syntax error\n", 1);
		line = "";
		return (line);
	}
	line[pipe_pos] = '\0';
	return(exec_pipes(line, new_input, data));
}

/*
** Fais les memes etapes que bash : 
** - Verifie d'abord les expands pour modifier l'input en foncton. 
** - Gere les pipes.
** - S'occupe des redirections
** - Tranforme l'input rendu propre en tableau de commandes.
*/
int		parser(char *line, t_data *data)
{
	int		i;
	char	quote;
	char	*new_line;

	i = 0;
	while (line[i])
	{
		if (line[i] == '$' && line[i + 1] != ' ')
		{
			new_line = manage_expand(line, data);
			line = new_line;
		}
		else if (line[i] == '|' && line[i + 1])
		{
			line = manage_pipe(line, i, data);
			i = -1;
			data->piped = true;
		}
		else if (line[i] == '"' || line[i] == '\'')
		{
			quote = line[i++];
			while(line[i] != quote)
			{
				if (line[i] == '$' && quote == '"')
				{
					new_line = manage_expand(line, data);
					line = new_line;
				}
				i++;
			}
		}
		i++;
	}
	// printf("%i  %i\n", data->std_out, data->std_in);
	// data->std_out = dup(1);
	// data->std_in = dup(0);
	// printf("%i  %i\n", data->std_out, data->std_in);
	return (parse_to_exec(line, data));
}
