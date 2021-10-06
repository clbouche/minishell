/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:14:21 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/09/30 09:09:58 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


int is_builtins(char **cmd)
{
    if(ft_strcmp("cd", cmd[0]) == 0)
        return(CD);
    else if(ft_strcmp("echo", cmd[0]) == 0)
        return(ECHO);
    else if(ft_strcmp("env", cmd[0]) == 0)
        return(ENV);
    else if(ft_strcmp("export", cmd[0]) == 0)
        return(EXPORT);
    else if(ft_strcmp("pwd", cmd[0]) == 0)
        return(PWD);
    else if(ft_strcmp("unset", cmd[0]) == 0)
        return(UNSET);
    else if(ft_strcmp("exit", cmd[0]) == 0)
        return(ft_exit());
    return(FAILURE);
}

void exec_builtin(int ret, char **cmd, t_data *d)
{
    
    if (is_builtins(cmd) == CD)
        ft_cd(cmd);
    else if (is_builtins(cmd) == ENV)
        ft_env(d);
    else if (is_builtins(cmd) == ECHO)
        ft_echo(cmd, d);
    else if (is_builtins(cmd) == EXPORT)
        ft_export(cmd, d);
    else if (is_builtins(cmd) == PWD)
        ft_pwd();
    else if (is_builtins(cmd) == UNSET)
       ft_unset(cmd, d);
    //else if (is_builtins(cmd) == EXIT)
        //ft_exit();
}
