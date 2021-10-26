/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:02:21 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/10/26 16:00:58 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(char **cmd, t_data *data)
{
	int	rtn;

	//dup2(data->std_in, 0);
	//dup2(data->std_out, 1);
	rtn = is_builtins(cmd);
	if (rtn != FAILURE)
        exec_builtin(cmd, data);
    else
        exec_simple(cmd, data);
	
}

void	exec_pipes(char *line, char *new_input, t_data *data)
{
	(void)line;
	(void)new_input;
	(void)data;
	int fd[2];
	
	if (pipe(fd) == -1)
		puts("error_pipe attention oublie pas dexit proprement");
	g_sig.pid = fork();
	if (g_sig.pid == -1)
		puts("error_pid attention oublie pas dexit proprement");//pening_error("Fork");	
	//dup2(fd[0], 0);
	//exec_simple(ft_split(line, ' '), data);
	//swap_fd()
	execute(ft_split(line, ' '), data);
	free(line);
	line = NULL;
	if (new_input != NULL)
		parser(new_input, data);
}


	// if (redirect(data) > 0 || data->pipe == true)
	// 	manage_fds(fd, data);