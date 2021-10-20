/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:12:46 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/20 16:19:41 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Permet de determiner si le delimiteur a ete croise ou non.
** Le delimiteur doit constituer l'integralite de la ligne. 
** Il ne doit pas juste "faire partie" de la ligne.
*/

bool	check_delimiter(char *line, char *delimiter)
{
	(void)line;
	(void)delimiter;
	if (ft_strcmp(delimiter, line))
		return (true);
	return (false);
}

void	heredoc_loop(char *delimiter, t_data *data)
{
	char	*input;

	(void)data;
	input = readline("> ");
	while(1)
	{
		// if (!line)
		// 	error

	}
}