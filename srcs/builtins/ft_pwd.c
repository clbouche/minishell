/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:25:32 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/22 11:24:40 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** writes the absolute pathname of the current working directory 
** to the standard output.
** -> there is a max size of 6 octets for the path
** ->
*/
int	ft_pwd(void)
{
	char	path[MAX];

	if (getcwd(path, MAX))
	{
		ft_putendl_fd(path, 1);
		return (SUCCESS);
	}
	else
	{
		perror("pwd");
		exit (FAILURE);
	}
}
