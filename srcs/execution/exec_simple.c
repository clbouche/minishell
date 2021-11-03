/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:49:47 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/11/03 17:14:35 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_sig sig;

void	exec_bin(char **cmd, char *bin, t_data *d)
{
	if (bin == NULL)
		free_exit(d, cmd[0], 127, ": command not found\n");
	g_sig.prog = 1;
    free(cmd[0]);
    cmd[0] = bin;
	if (execve(bin, cmd, d->envp) == -1)
		free_exit(d, cmd[0], 126, ": file is not an excutable\n");
}

void    exec_child(char **cmd, t_data *d)
{
    char *bin;
    char **paths;

    bin = NULL;
    if (d->have_path == false)
    {
        paths = get_path(d);
        bin = find_bin(paths, cmd);
    }
    else
    {
        convert_env(d);
        bin = ft_strdup(cmd[0]);
    }
    exec_bin(cmd, bin, d);
}

void exec_simple(char **cmd, t_data *d)
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
