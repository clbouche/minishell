/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:49:47 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/10/06 18:41:31 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void exec_simple(char  **cmd, t_data *d)
{
    int pid;

    pid = fork();
    if (pid == -1)
		opening_error("Fork");
    else if (pid > 0)
        exec_parent(cmd, d);
    else if (pid == 0)
        exec_child(cmd, d);
        
}

// void    exec_child(char **cmd, t_data *d)
// {
//     dup2(STDIN_FILENO, 0);
//     get_path(cmd, d);
// }
// void    exec_parent(char **cmd, t_data *d)
// {
//     puts("caca");
// }
