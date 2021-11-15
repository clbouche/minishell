/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:22:30 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/15 11:23:04 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list *check_exist_var(char *name, t_data *data)
{
	t_list	*tmp;
	//char	*name_var;

	tmp = data->env;
	ft_putstr_fd(name, 1);
	while(tmp->next != NULL)
	{
		//name_var = find_name(tmp->content);
		//ft_putstr_fd(name_var, 1);
		if (ft_strncmp(name, tmp->content, ft_strlen(name)) == 1)
		{
			ft_putstr_fd(tmp->content, 1);
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

bool	check_char_file(char c)
{
	if (ft_isalpha(c) || c == '_' || ft_isalnum(c) || c == '$' || c == '%' 
	|| c == '{' || c == '}' || c == '.')
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