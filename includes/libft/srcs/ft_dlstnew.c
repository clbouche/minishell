/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:48:01 by claclou           #+#    #+#             */
/*   Updated: 2021/09/09 11:10:46 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_dlist	*ft_dlstnew(char *content)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	new->begin = NULL;
	new->end = NULL;
	new->len = 0;
	return (new);
}
