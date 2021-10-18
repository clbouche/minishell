/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:02:21 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/10/15 13:23:06 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(char **cmd, t_data *data)
{
	int	rtn;

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
	printf("pipe\n");
}