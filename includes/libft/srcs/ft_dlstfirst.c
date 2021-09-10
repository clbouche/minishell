/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfirst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:03:41 by claclou           #+#    #+#             */
/*   Updated: 2021/09/09 11:17:43 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_dlstfirst(t_dlist *lst)
{
	if (lst == NULL)
		return (0);
	return (lst->begin->value);
}
