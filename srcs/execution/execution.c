/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:02:21 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/11/22 14:42:00 by ldes-cou         ###   ########.fr       */
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

void add_to_array(t_data *d, pid_t pid)
{
	d->pid_array[d->pid] = pid;
	d->pid++;
} 
char	*exec_pipes(char *line, char *new_input, t_data *d)
{
	pid_t pid;
	
	if (pipe(d->fds) == -1)
		puts("error_pipe attention oublie pas dexit proprement");
	pid = fork();
	add_to_array(d, pid);
	if (g_sig.pid == -1)
		puts("error_pid attention oublie pas dexit proprement");//pening_error("Fork");	
	if (g_sig.pid == 0)
	{
		pipe_out(d);
		parse_to_exec(line, d);
		exit(g_sig.status);
	}
	else if (g_sig.pid < 0)
		exit(FAILURE);
	pipe_in(d);
	free(line);
	return (new_input);
}
