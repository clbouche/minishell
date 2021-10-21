/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:02:21 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/10/21 12:25:09 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int redirect(t_data *d)
{
	int ret;
	
	ret = 0;
	if (std_out != 1)
		ret = 1;
	if (std_in != 0)
		ret += 2;
	return (ret);
}
void	manage_fds(t_data *d)
{
	if (d->std_out != 1)
		close(d->std_out);
	if (d->pipe == true)
	{
		close(fd[1]);
		dup2(fd[0], 0);
	}
	g_sig.prog = 1;        
    g_sig.pid = fork();
    if (g_sig.pid == -1)
	  	puts("error_pid attention oublie pas dexit proprement");
	///opening_error("Fork");
}
void	execute(int *fd, char **cmd, t_data *d)
{
	int	rtn;

	rtn = is_builtins(cmd);
	if (redirect(d) > 0 || d
	->pipe == true)
		manage_fds(d);
	if (rtn != FAILURE)
        exec_builtin(cmd, d);
    else
        exec_simple(fd, cmd, d);
}

void	exec_pipes(char *line, char *new_input, t_data *data)
{
	(void)line;
	(void)new_input;
	(void)data;
	int fd[2];
	
	// int	fd[2];
	//printf("pipe\n");
	printf("line == %s\n", line);
	printf("new_input == %s\n", new_input);
	if (pipe(fd) == -1)
		puts("error_pipe attention oublie pas dexit proprement");
	g_sig.pid = fork();
	if (g_sig.pid == -1)
		puts("error_pid attention oublie pas dexit proprement");//pening_error("Fork");	
	dup2(fd[0], 0);
	//exec_simple(ft_split(line, ' '), data);
	//swap_fd()
	execute(fd, ft_split(line, ' '), data);
	free(line);
	line = NULL;
	parser(new_input, data);
}

