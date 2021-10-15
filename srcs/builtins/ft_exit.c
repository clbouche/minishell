/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 10:32:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/15 17:15:24 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** ends a process. Took 2 args max and the second one it's numeric. 
** It's not allowed to have option.
** make a function to ctrl numbers of arg
*/


// static int	is_numeric(char *input)
// {
// 	int	i;

// 	i = 0;
// 	while (input[i])
// 	{
// 		if ((!(input[i] >= '0' && input[i] <= '9') && !(input[i] == '-' )))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }



// int	ft_exit(char **cmd, t_data *d)
// {

//     int exit_code;

//     exit_code = 0;
//     d->ret = 0;
//     ft_putendl_fd("exit", 1);
//     if (is_numeric(cmd[1]))
//     {
//         ft_putstr_fd("exit: ", 2);
//         ft_putstr_fd(cmd[1], 2);
//         ft_putstr_fd(": numeric argument required", 2);
//         exit_code = 1;
//     }
//     else
//     {
//         if (cmd[1] != NULL)
//             exit_code = ft_atoi(cmd[1]);
//     }
//     free_lst(d->env);
//     exit(exit_code);
// }

int ft_exit()
{
    ft_putendl_fd("exit", 1);
    exit(0);
}
