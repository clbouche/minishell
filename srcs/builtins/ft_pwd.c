/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:25:32 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/14 09:47:47 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** writes the absolute pathname of the current working directory 
** to the standard output.
** -> there is a max size of 6 octets for the path
** ->
*/ 

void	ft_pwd()
{
    char path[MAX];

    if (getcwd(path, sizeof(path)) != NULL)
        printf("%s", path);
    else
        perror("pwd");
}