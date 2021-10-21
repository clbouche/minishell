/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:49:47 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/10/21 12:04:10 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_sig sig;

int redirect(t_data *d)
{
    bool ret;

    ret = false; 
    if (d->std_in != 0)    
    {
        dup2(d->std_in, 0);
        ret = true;
    }
    if (d->std_out != 1)
    {
        dup2(d->std_out, 1);
        ret = true;
    }
    return(ret);
}

void    exec_child(int *fd, char **cmd, t_data *d)
{
    char *bin;
    char **paths;

    if(redirect(d) == true)
    {
        close(d->std_in);
	    dup2(d->std_out, 1);
    }
    if(d->pipe = true)
    [
        close(fd[0])
        dup2(fd[1])
    ]
    paths = get_path(d);
    bin = find_bin(paths, cmd);
    exec_bin(cmd, bin, d);
}

void exec_simple(int fd*, char  **cmd, t_data *d)
{

    if (g_sig.pid == 0)
        exec_child(fd, cmd, d);
    else
    {
        waitpid(-1, &g_sig.status, 0);
        free_array(cmd);
    }
    if (WIFEXITED(g_sig.status))
        g_sig.status = WEXITSTATUS(g_sig.status);
    g_sig.prog = 0;
}
