/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:04:57 by claclou           #+#    #+#             */
/*   Updated: 2021/09/20 11:11:02 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../../minishell.h"

t_dlist	*ft_dlstadd_back(t_dlist *lst, char *content)
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
