/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_realloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:54:41 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/18 14:55:21 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Concatenates two strings and add the second to the first one on the same
**	memory location
**
**	@param s1 First string
**	@param s2 Seconde string
**	@param Pointer to the new string
*/
char	*ft_strjoin_realloc(char **s1, char *s2)
{
	char	*res;
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(*s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (*s1 && (*s1)[++i] != '\0')
		res[j++] = (*s1)[i];
	i = -1;
	while (s2 && s2[++i] != '\0')
		res[j++] = s2[i];
	if (*s1)
		free(*s1);
	res[j] = '\0';
	*s1 = res;
	return (res);
}
