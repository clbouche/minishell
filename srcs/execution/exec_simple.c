/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:49:47 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/11/17 15:14:48 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
	
void	exec_bin(char **cmd, char *bin, t_data *d)
{
	struct  stat stat_b;
	if (bin == NULL)
		free_exit(d, cmd[0], 127, ": command not found\n");
	free(cmd[0]);
	cmd[0] = bin;
	if ((stat(bin, &stat_b) == 0 && stat_b.st_mode & S_IXUSR))
	{
		if (execve(bin, cmd, d->envp) == -1)
		{
			write(1, "exec_error\n", 11);
			free_array(cmd);
			cmd = NULL;
		}
	}
	g_sig.prog = 1;
	g_sig.status = 1;
	free_array(cmd);
	cmd = NULL;
	exit(g_sig.status);
}

void    exec_child(char **cmd, t_data *d)
{
	char *bin;
	char **paths;

	paths = NULL;
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
	//free(bin);
}



void exec_simple(char **cmd, t_data *d)
{ 
	g_sig.prog = 1;
	g_sig.pid = fork();
	if (g_sig.pid == -1)
	{
		puts("error_pid attention oublie pas dexit proprement");
		exit(FAILURE);
	}
	else if (g_sig.pid == 0)
		exec_child(cmd, d);
	else
	{
		waitpid(g_sig.pid, &g_sig.status, 0);
		free_array(cmd);
	}
	if (WIFEXITED(g_sig.status))
		g_sig.status = WEXITSTATUS(g_sig.status);
	g_sig.prog = 0;
	//close_fds(d);
	return;
}
