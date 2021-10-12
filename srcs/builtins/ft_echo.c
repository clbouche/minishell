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
extern t_sig g_sig;

int	ft_echo(char **cmd, t_data *d)
{

    (void)d;
    if (cmd[1][1] == 'n')
        ft_putstr_fd(cmd[2], 1);//faire ecrire sur la line
    else if(!ft_strncmp(cmd[1], "$?", 2))
    {
        printf("%i\n", g_sig.status);
        // ft_putchar_fd((g_sig.status), 1);
        // ft_putchar_fd('\n', 1);
    }
    else
    {
        ft_putstr_fd(cmd[1], 1);
        ft_putstr_fd("\n", 1);
    }
    return (0);
}
