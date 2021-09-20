/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:02 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/20 11:25:34 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//#SUPPRIMER PRINT LIST#

void	print_dlist(t_dlist *lst)
{
	t_node	*temp;

	temp = lst->begin;
	if (lst == NULL)
		ft_error(ERR_EMPTY_DLIST);
	while (temp != NULL)
	{
		printf("[%s]\n", temp->value);
		temp = temp->next;
	}
}

t_dlist	*init_list(t_dlist *list)
{
	list = malloc(sizeof(t_dlist));
	if (!list)
		exit(0);
	list->end = NULL;
	list->begin = NULL;
	list->len = 0;
	return (list);
}

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
		ft_dlstadd_back(list, split_line[i]);
		i++;
	}
	print_dlist(list);
	put_token(list);
}