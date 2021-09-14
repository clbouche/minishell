/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:37:43 by claclou           #+#    #+#             */
/*   Updated: 2021/09/14 15:53:00 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_dlist	*ft_add_node(t_dlist *lst, char *content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL || lst == NULL)
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