/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:18:32 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/16 13:31:03 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Echo function write (illimiteds) arguments
** to the standard output with a new line 
** unless the -n option is set. 
*/

int	ft_echo(char **cmd)
{
    char option;

    option = cmd[1][1];
    if (option == 'n')
        ft_putstr_fd(cmd[2], 1);
    else
    {
        ft_putstr_fd("\n", 1);
        ft_putstr_fd(cmd[1], 1);
    }
    return (0);
}
