/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:02 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/17 11:54:27 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parser(char *line)
{
	int i;
	t_dlist *list;
	char **split_line;

	i = 0;
	list = init_list(list);
	if (!line)
		exit(0);
	split_line = ft_split(line, ' ');
	while (split_line[i] != NULL)
	{
		ft_add_node(list, split_line[i]);
		i++;
	}
	print_dlist(list);
	put_token(list);
}