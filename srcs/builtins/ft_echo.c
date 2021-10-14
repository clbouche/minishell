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

static int handle_option(char **cmd, int i)
{
    char *str;
    char*tmp;

    str = NULL;
    tmp = NULL;
    while(ft_strncmp(cmd[i], "-n", 2))
            i++;
    while (cmd[i + 1] != NULL)
    {
        if (cmd[i + 2] != NULL)
        {
            printf("affiche moi ca :[cmd %i] == %s\n", i, cmd[i + 1]);
            tmp = ft_strjoin(cmd[i + 1], " ");
            str = ft_strjoin(str, tmp);
            free(tmp);
        }
        else
        {
            printf("else :[cmd %i] == %s\n", i, cmd[i + 1]);
            str = ft_strjoin(str, cmd[i + 1]);
        }
        i++;
    }
    ft_putstr_fd(str, 1);
    free(str);
    return(0);
}
int	ft_echo(char **cmd, t_data *d)
{
    int i;
    char *str;
    char*tmp;

    str = NULL;
    tmp = NULL;
    i = 1;
    (void)d;
    if(!ft_strncmp(cmd[1], "$?", 2))
        printf("%i\n", g_sig.status);
    if (!ft_strncmp(cmd[i], "-n", 2))
        return (handle_option(cmd, i));
    else
    {
        while (cmd[i] != NULL)
        {
            tmp = ft_strjoin(cmd[i], " ");
            str = ft_strjoin(str, tmp);
            //ft_putstr_fd(cmd[i], 1);
            free(tmp);
            i++;
        }
        ft_putstr_fd(str, 1);
        ft_putstr_fd("\n", 1);
    }
    free(str);
    return (0);
}
