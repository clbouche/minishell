/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:07:33 by claclou           #+#    #+#             */
/*   Updated: 2021/09/09 11:17:15 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
