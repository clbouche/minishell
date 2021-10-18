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

#include "minishell.h"

/* Echo function write (illimiteds) arguments
** to the standard output with a new line 
** unless the -n option is set. 
*/

static int handle_multiarg(char **cmd, int i)
{
    char *str;
    char*tmp;

    str = NULL;
    tmp = NULL;
    while (cmd[i] != NULL)
    {
        if (cmd[i + 1] != NULL)
        {
            ft_putchar_fd(' ', 1);
            ft_putstr_fd(cmd[i], 1);
        }
        else
            ft_putstr_fd(cmd[i], 1);
        i++;
    }
    return(0);
}

int	ft_echo(char **cmd, t_data *d)
{
    int i;

    i = 1;
    (void)d;
    if(!ft_strncmp(cmd[1], "$?", 2))
        printf("%i\n", g_sig.status);
    if (ft_strcmp(cmd[i], "-n") == 0)
    {
        //puts("here");
        while(ft_strcmp(cmd[i + 1], "-n") == 0)
            i++;
        handle_multiarg(cmd, i + 1);
    }
    else
    {
        handle_multiarg(cmd, i);
        ft_putchar_fd('\n', 1);
    }
    return (0);
}
