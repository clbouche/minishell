/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:02 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/03 11:44:20 by claclou          ###   ########.fr       */
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
	{
		redir_output_append(&input[i + 2], data);
		input[i + 1] = '\0';
	}
	else if (input[i] == '<' && input[i + 1] != '<')
		redir_input(&input[i + 1], data);
	else if (input[i] == '<' && input[i + 1] == '<')
	{
		redir_read_input(&input[i + 2], data);
		input[i + 1] = '\0';
	}
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
			if (line[i + 1] && (line[i + 1] == '?' || check_char_begin(line[i + 1])))
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

bool	check_closed_quotes(char *line)
{
	int	i;
	int	nb_doble_quotes;
	int	nb_simple_quotes;

	i = 0;
	nb_simple_quotes = 0;
	nb_doble_quotes = 0;
	while(line[i])
	{
		if (line[i] == '"')
			nb_doble_quotes += 1;
		if (line[i] == '\'')
			nb_simple_quotes += 1;
		i++;
	}
	if (nb_simple_quotes % 2 == 0 && nb_doble_quotes % 2 == 0)
		return (true);
	return (false);
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
	bool	closed_quotes;

	i = 0;
	closed_quotes = check_closed_quotes(line);
	//peut etre a supprimer, create input pourrait traiter ca ? 
	while (line[i])
	{
		if (line[i] == '$')
		{
			new_line = manage_expand(line, data);
			line = new_line;
		}
		if (line[i] == '|' && line[i + 1])
		{
			manage_pipe (line, i, data);
			data->pipe = true;
		}
		if (line[i] == '"' || line[i] == '\'')
		{
			quote = line[i];
			if (closed_quotes == true)
			{
				if (line[i] == '$' && quote == '"')
				{
					new_line = manage_expand(line, data);
					line = new_line;
				}
			}
			else
				exit(0);
		}
		i++;
	}
	return (parse_to_exec(line, data));
}
