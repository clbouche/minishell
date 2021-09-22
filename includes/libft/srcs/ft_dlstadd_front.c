/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:06:58 by claclou           #+#    #+#             */
/*   Updated: 2021/09/20 11:27:25 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_dlist	*ft_dlstadd_front(t_dlist *lst, char *content)
{
	t_node	 *new_node;

	new_node = malloc(sizeof(t_node));
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
		lst->begin->prev = new_node;
		new_node->next = lst->begin;
		lst->begin = new_node;
	}
	lst->len += 1;
	return (lst);
}
