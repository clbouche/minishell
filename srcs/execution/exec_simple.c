/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:49:47 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/10/31 15:10:48 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_sig sig;

void    exec_child(char **cmd, t_data *d)
{
    char *bin;
    char **paths;

    paths = get_path(d);
    bin = find_bin(paths, cmd);
    exec_bin(cmd, bin, d);
}

void exec_simple(char  **cmd, t_data *d)
{ 
    g_sig.prog = 1;
    g_sig.pid = fork();
    if (g_sig.pid == -1)
	  	puts("error_pid attention oublie pas dexit proprement");
    if (g_sig.pid == 0)
        exec_child(cmd, d);
    else
    {
        waitpid(g_sig.pid, &g_sig.status, 0);
        free_array(cmd);
        close_fds(d);
    }
    if (WIFEXITED(g_sig.status))
        g_sig.status = WEXITSTATUS(g_sig.status);
    g_sig.prog = 0;
}
