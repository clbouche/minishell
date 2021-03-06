/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:59:23 by claclou           #+#    #+#             */
/*   Updated: 2021/12/03 09:31:04 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	count_childs(char *cmd, t_data *data)
{
	int	i;

	data->pid = 0;
	data->pipes = 0;
	i = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '|')
			data->pipes++;
		i++;
	}
	data->pipes += data->redir->count_heredoc;
}

void	malloc_pid_array(t_data *data)
{
	data->pid_array = (pid_t *)malloc(sizeof(pid_t) * (data->pipes + 1));
	ft_bzero(data->pid_array, (sizeof(pid_t) * (data->pipes + 1)));
	if (data->pid_array == NULL)
		exit(FAILURE);
}

void	add_to_array(t_data *d, pid_t pid)
{
	d->pid_array[d->pid] = pid;
	d->pid++;
}

char	*exec_pipes(char *line, char *new_input, t_data *d)
{
	pid_t	pid;

	if (pipe(d->fds) == -1)
		puts("error_pipe attention oublie pas dexit proprement");
	pid = fork();
	add_to_array(d, pid);
	if (pid == -1)
		puts("error_pid attention oublie pas dexit proprement");
	if (pid == 0)
	{
		pipe_out(d);
		parse_to_exec(line, d);
		exit(g_sig.status);
	}
	else if (pid < 0)
		exit(FAILURE);
	pipe_in(d);
	free(line);
	return (new_input);
}

void	wait_for_childs(t_data *data)
{
	int	i;
	int	status;

	status = g_sig.status;
	i = 0;
	while (i < data->pid)
	{
		waitpid(data->pid_array[i], &status, 0);
		i++;
	}
	if (WIFEXITED(status))
		g_sig.status = WEXITSTATUS(status);
	free(data->pid_array);
}
