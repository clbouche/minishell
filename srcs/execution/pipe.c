/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:37:16 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/11/23 14:00:33 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	malloc_pid_array(t_data *data)
{
	data->pid_array = (pid_t *)malloc(sizeof(pid_t) * (data->pipes + 1));
    if (data->pid_array == NULL)
        return(FAILURE);
	ft_bzero(data->pid_array, (sizeof(pid_t) * (data->pipes + 1)));
    
}

void add_to_array(t_data *d, pid_t pid)
{
	d->pid_array[d->pid] = pid;
	d->pid++;
}

char	*exec_pipes(char *line, char *new_input, t_data *d)
{
    pid_t   pid;

	if (pipe(d->fds) == -1)
		puts("error_pipe attention oublie pas dexit proprement");
	pid = fork();
	add_to_array(d, pid);
	if (pid == -1)
		puts("error_pid attention oublie pas dexit proprement");//pening_error("Fork");	
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

void    
{
    int i = 0;
    while(i <= data->pipes)
    {
        waitpid(data->pid_array[i], &g_sig.status, 0);
        i++;
    }
    free(data->pid_array)
}