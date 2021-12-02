/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:22:30 by clbouche          #+#    #+#             */
/*   Updated: 2021/12/02 14:12:55 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_char_file(char c)
{
	if (ft_isalpha(c) || c == '_' || ft_isalnum(c) || c == '$' || c == '%'
		|| c == '{' || c == '}' || c == '.' || c == '/' || c == '\''
		|| c == '"')
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
