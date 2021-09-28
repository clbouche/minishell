/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:25:32 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/27 15:18:56 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** writes the absolute pathname of the current working directory 
** to the standard output.
** -> there is a max size of 6 octets for the path
** ->
*/ 

int	ft_pwd(void)
{
    char path[MAX];

    if (getcwd(path, MAX))
    {
        ft_putendl_fd(path, 1);
        return(SUCCESS);
    }
    else
    {
        perror("pwd");
        exit(FAILURE);
    }  
}