/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:02:21 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/11/07 15:02:32 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(char **cmd, t_data *d)
{
	d->have_path = false;
	if (ft_strchr(cmd[0], '/'))
		d->have_path = true;
	if (is_builtins(cmd) != FAILURE)
		exec_builtin(cmd, d);
    else
        exec_simple(cmd, d);
	close_fds(d);
}

char	*exec_pipes(char *line, char *new_input, t_data *d)
{
	(void)line;
	(void)new_input;
	(void)d;
	char **input;

	d->std_out = dup(1);
	d->std_in = dup(0);
	d->piped = true;
	if (pipe(d->fds) == -1)
		puts("error_pipe attention oublie pas dexit proprement");
	input = ft_split(line, ' ');
	ft_memdel(&line);
	g_sig.pid = fork();
	if (g_sig.pid == -1)
		puts("error_pid attention oublie pas dexit proprement");//pening_error("Fork");	
	if (g_sig.pid == 0)
	{
		//free(line);
		open_fds(d);
		execute(input, d);
	}
	else if (g_sig.pid < 0)
		exit(FAILURE);
	switch_fds(d);
	//execute(input, d);
	return (new_input);
}