/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:32:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/18 12:42:10 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** ends a process. Took 2 args max and the second one it's numeric. 
** It's not allowed to have option.
** make a function to ctrl numbers of arg
*/


static int	is_numeric(char *input)
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

static int numeric_arg_required(char *arg)
{
    ft_putstr_fd("minishell: exit: ", 2);
    ft_putstr_fd(arg, 2);
    ft_putstr_fd(": numeric argument required", 2);
    ft_putstr_fd("\n", 2);
    g_sig.status = FAILURE;
    return (g_sig.status);
}

int     ft_exit(char **cmd, t_data *d)
{
    int exit_code;

    exit_code = 0;
    d->ret = 0;
    ft_putendl_fd("exit", 1);
    // if (cmd[2] != NULL)
    //     ft_putendl_fd("minishell: exit: too many arguments", 2);
    if (is_numeric(cmd[1]) == 1)
        return(numeric_arg_required(cmd[1]));
    else
    {
        if (cmd[1] != NULL)
        {
            exit_code = ft_atoi(cmd[1]);
            exit(exit_code);
        }
    }
    free_lst(d->env);
    return(FAILURE);
}

// int ft_exit()
// {
//     ft_putendl_fd("exit", 1);
//     exit(0);
// }
