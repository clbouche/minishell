/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:49:47 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/10/07 11:37:26 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void exec_simple(char  **cmd, t_data *d)
{
    int pid;
    int ret = 0;

    pid = fork();
    if (pid == -1)
	  	opening_error("Fork");
    if (pid == 0)
        exec_child(cmd, d);
    waitpid(-1, &ret, 0);
    printf("%i\n", ret);
        
}

void    exec_child(char **cmd, t_data *d)
{
    dup(0);
    get_path(cmd, d);
}
// //void    exec_parent(char **cmd, t_data *d)
// {
//     //puts("caca");
// }
