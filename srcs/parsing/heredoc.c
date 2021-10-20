/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:12:46 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/20 17:45:07 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Permet de determiner si le delimiteur a ete croise ou non.
** Le delimiteur doit constituer l'integralite de la ligne. 
** Il ne doit pas juste "faire partie" de la ligne.
*/

bool	check_delimiter(char *input, char *delimiter)
{
	if (ft_strcmp(delimiter, input) == 0)
		return (true);
	return (false);
}

void	heredoc_loop(char *delimiter, t_data *data, int *heredocs)
{
	char	*input;

	(void)data;
	while(1)
	{
		input = readline("> ");
		if (ft_strcmp(input, delimiter) == 0)
		{
			free(input);
			break;
		}
		write(heredocs[1], input, ft_strlen(input));
		write(heredocs[1], "\n", 1);
	}
	//free(input);
}