/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:02:21 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/11/12 15:41:55 by ldes-cou         ###   ########.fr       */
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
	d->std_out = dup(1);
	d->std_in = dup(0);	
	if (pipe(d->fds) == -1)
		puts("error_pipe attention oublie pas dexit proprement");
	g_sig.pid = fork();
	if (g_sig.pid == -1)
		puts("error_pid attention oublie pas dexit proprement");//pening_error("Fork");	
	if (g_sig.pid == 0)
	{
		open_fds(d);
		parse_to_exec(line, d);
		exit(g_sig.status);
	}
	else if (g_sig.pid < 0)
		exit(FAILURE);
	switch_fds(d);
	//execute(input, d);
	free(line);
	//close_fds(d);
	return (new_input);
}
