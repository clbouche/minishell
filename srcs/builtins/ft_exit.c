/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:32:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/12/03 10:04:04 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** ends a process. Took 2 args max and the second one it's numeric. 
** It's not allowed to have option.
** make a function to ctrl numbers of arg
*/

/* if its piped should not exit
**  shuould return the last arg of exit
*/
int	is_numeric(char *input)
{
	int	i;

	i = 0;
	while (input && input[i] != '\0')
	{
		if ((!(input[i] >= '0' && input[i] <= '9') && !(input[i] == '-' )))
			return (1);
		i++;
	}
	return (0);
}

static int	numeric_arg_required(char *arg)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": numeric argument required", 2);
	ft_putstr_fd("\n", 2);
	g_sig.status = FAILURE;
	return (g_sig.status);
}

void	exit_with_status(char **cmd, t_data *d)
{
	int	exit_code;

	exit_code = 0;
	exit_code = ft_atoi(cmd[1]);
	if (WIFEXITED(exit_code))
		exit_code = WEXITSTATUS(exit_code);
	free_all(d, cmd);
	exit(exit_code);
}

int	ft_exit(char **cmd, t_data *d)
{
	d->ret = 0;
	ft_putendl_fd("exit", 2);
	if (cmd[1] && cmd[2] != NULL)
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		return (FAILURE);
	}
	if (is_numeric(cmd[1]) == 1)
	{
		numeric_arg_required(cmd[1]);
		exit(128);
	}
	else
	{
		if (cmd[1] != NULL)
			exit_with_status(cmd, d);
	}
	free_all(d, cmd);
	exit(SUCCESS);
}
