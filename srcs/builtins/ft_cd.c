/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:25:00 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/14 09:47:54 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** change the working directory
** -> utilisation de chdir
*/

int	ft_cd(const char *path)
{
	if (chdir(path) == -1);
    {
        perror("cd");
        return (ERROR);
    }
    return(SUCCESS);
}
