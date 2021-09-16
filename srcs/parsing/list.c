/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:37:43 by claclou           #+#    #+#             */
/*   Updated: 2021/09/16 12:57:25 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

void	ft_delete_node(t_dlist *list)
{
	t_node *begin;

	begin = list->begin;
	if (list == NULL)
		ft_error(ERR_EMPTY_DLIST);
	if (list->begin == list->end)
	{
		list->len -= 1;
		list->begin = NULL;
		list = NULL;
		return ;
	}
	list->begin = list->begin->next;
	list->begin->prev = NULL;
	begin->next = NULL;
	begin->prev = NULL;
	begin->value = 0;
	free(begin);
	list->len -= 1;
}

t_dlist	*ft_add_node(t_dlist *lst, char *content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (lst == NULL || new_node == NULL)
		ft_error(ERR_ALLOC);
	new_node->value = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (lst->len == 0)
	{
		lst->begin = new_node;
		lst->end = new_node;
	}
	else
	{
		lst->end->next = new_node;
		new_node->prev = lst->end;
		lst->end = new_node;
	}
	lst->len += 1;
	return (lst);
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
