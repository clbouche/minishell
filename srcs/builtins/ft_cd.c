/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:25:00 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/27 15:05:13 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** change the working directory
** -> utilisation de chdir
*/

int	ft_cd(char **cmd)
{
    char *path;

    path = NULL;
    path = ft_strdup(cmd[1]);
	if (chdir(path) == -1)
    {
        perror("cd");
        free(path);
        exit(FAILURE);
    }
    return(SUCCESS);
}
