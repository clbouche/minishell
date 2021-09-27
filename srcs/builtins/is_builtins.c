/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:14:21 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/09/27 15:28:55 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// static t_built my_builtins[] =
// {
//     {"cd", ft_cd},
//     {"echo", ft_echo},
//     {"env", ft_env},
//     {"exit", ft_exit},
//     {"export", ft_export},
//     {"unset", ft_unset},
//     {NULL, NULL},
// };
          
// void *is_builtin(char *input)
// {
//     int i;
//     t_built *my_builtins;
    
//     i = 0;
//     while(my_builtins[i].name != NULL)
//     {
//         puts("here");
//         //printf("%i\n", ft_strcmp(input, my_builtins[i].name));
//         if (ft_strcmp(input, my_builtins[i].name) == 0)
//             return(my_builtins[i].func);
//         i++;
//     }
//     return(NULL);
// }

int is_builtins(char **cmd)
{
    if(ft_strcmp(cmd[0], "cd") == 0)
        return(ft_cd(cmd));
    else if(ft_strcmp(cmd[0], "echo") == 0)
        return(ft_echo(cmd));
    else if(ft_strcmp(cmd[0], "env") == 0)
        return(ft_env());
    else if(ft_strcmp(cmd[0], "export") == 0)
        return(ft_export(cmd));
    else if(ft_strcmp(cmd[0], "pwd") == 0)
        return(ft_pwd());
    else if(ft_strcmp(cmd[0], "unset") == 0)
        return(ft_unset(cmd));
    else if(ft_strcmp(cmd[0], "exit") == 0)
        return(ft_exit());
    return(FAILURE);
}



