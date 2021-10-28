/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:22:30 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/28 13:57:28 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_exist_var(char *name, t_data *data)
{
	t_list	*tmp;
	char	*name_var;

	tmp = data->env;
	while(tmp != NULL)
	{
		name_var = find_name(tmp->content);
		if (ft_strcmp(name, name_var) == 0)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

bool	check_closed_quotes(char *line)
{
	int	i;
	int	nb_doble_quotes;
	int	nb_simple_quotes;

	i = 0;
	nb_doble_quotes = 1;
	nb_simple_quotes = 1;
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

bool	check_char_file(char c)
{
	if (ft_isalpha(c) || c == '_' || ft_isalnum(c) || c == '$' || c == '%' 
	|| c == '{' || c == '}')
		return (true);
	return (false);
}

bool	check_char_begin(char c)
{
	if (c == '_' || ft_isalpha(c))
		return (true);
	return (false);
}

bool	check_char(char c)
{
	if (c == '_' || ft_isalnum(c))
		return (true);
	return (false);
}

bool	spe_case(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == ' '
		|| c == '\'' || c == '"')
		return (true);
	return (false);
}