/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:22:30 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/02 15:33:51 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list *check_exist_var(char *name, t_data *data)
{
	t_list	*tmp;
	char	*name_var;

	tmp = data->env;
	while(tmp != NULL)
	{
		name_var = find_name(tmp->content);
		if (ft_strcmp(name, name_var) == 1)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
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