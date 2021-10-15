/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:14:21 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/10/15 17:15:35 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int is_builtins(char **cmd)
{
    if(ft_strcmp("cd", cmd[0]) == 0)
        return(FT_CD);
    else if(ft_strcmp("echo", cmd[0]) == 0)
        return(FT_ECHO);
    else if(ft_strcmp("env", cmd[0]) == 0)
        return(FT_ENV);
    else if(ft_strcmp("export", cmd[0]) == 0)
        return(FT_EXPORT);
    else if(ft_strcmp("pwd", cmd[0]) == 0)
        return(FT_PWD);
    else if(ft_strcmp("unset", cmd[0]) == 0)
        return(FT_UNSET);
    else if(ft_strcmp("exit", cmd[0]) == 0)
        return(EXIT);
    return(FAILURE);
}

void exec_builtin(char **cmd, t_data *d)
{
    
    if (is_builtins(cmd) == FT_CD)
        ft_cd(cmd);
    else if (is_builtins(cmd) == FT_ENV)
        ft_env(d);
    else if (is_builtins(cmd) == FT_ECHO)
        ft_echo(cmd, d);
    else if (is_builtins(cmd) == FT_EXPORT)
        ft_export(cmd, d);
    else if (is_builtins(cmd) == FT_PWD)
        ft_pwd();
    else if (is_builtins(cmd) == FT_UNSET)
       ft_unset(cmd, d);
    else if (is_builtins(cmd) == EXIT)
        ft_exit();
    //ft_exit(cmd, d);
}
