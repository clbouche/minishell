/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:02 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/14 15:57:14 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*PRINTF A SUPPR*/

void	put_token(char **line, t_dlist *list)
{
	int i;
	

	i = 0;
	while (line[i] != NULL)
	{
		ft_add_node(list, line[i]);
	}
}

void	parser(char *line, t_dlist *list)
{
	char **split_line;

	if (line)
	{
		split_line = ft_split(line, ' ');
		put_token(split_line, list);
	}
	else 
		exit(0);
}