/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:37:16 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/11/23 12:38:44 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void add_to_array(t_data *d, pid_t pid)
{
	d->pid_array[d->pid] = pid;
	d->pid++;
}

char	*exec_pipes(char *line, char *new_input, t_data *d)
{
	//pid_t pid;
	
	if (pipe(d->fds) == -1)
		puts("error_pipe attention oublie pas dexit proprement");
	g_sig.pid = fork();
	//add_to_array(d, pid);
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
