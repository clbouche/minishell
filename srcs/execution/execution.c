/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:02:21 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/11/24 13:30:07 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(char **cmd, t_data *d)
{
	// int i = 0;
	// while (cmd[i])
	// {
	// 	printf("cmd == %s\n", cmd[i]);
	// 	i++;
	// }
	if (g_sig.sigint == 1)
	{
		free_array(cmd);
		return;
	}
	d->have_path = false;
	if (ft_strchr(cmd[0], '/'))
		d->have_path = true;
	if (is_builtins(cmd) != FAILURE)
		exec_builtin(cmd, d);
	else
		exec_simple(cmd, d);
}


static void	exec_bin(char **cmd, char *bin, t_data *d)
{
	struct  stat stat_b;
	
	signal(SIGINT, &sig_int);
	signal(SIGQUIT, &sig_quit);
	if (bin == NULL)
		free_exit(d, cmd[0], 127, ": command not found\n");
	free(cmd[0]);
	cmd[0] = bin;
	if ((stat(bin, &stat_b) == 0 && stat_b.st_mode & S_IXUSR))
	{
		if (execve(bin, cmd, d->envp) == -1)
		{
			write(1, "exec_error\n", 11);
		}
	}
	g_sig.status = 126;
	free_array(cmd);
	cmd = NULL;
	g_sig.prog = 0;
	exit(g_sig.status);
}

static void    exec_child(char **cmd, t_data *d)
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
}

void exec_simple(char **cmd, t_data *d)
{
	g_sig.pid = fork();
	g_sig.prog = 1;
	if (g_sig.pid == -1)
		free_exit(d, cmd[0], 1, ": error while forking\n");
	else if (g_sig.pid == 0)
		exec_child(cmd, d);
	signal(SIGQUIT, &sig_quit);
	waitpid(g_sig.pid, &g_sig.status, 0);
	free_array(cmd);
	if (WIFEXITED(g_sig.status))
		g_sig.status = WEXITSTATUS(g_sig.status);
	g_sig.prog = 0;
	return;
}
