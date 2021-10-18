/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:49:47 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/10/18 16:54:27 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_sig sig;

void    exec_child(char **cmd, t_data *d)
{
    //dup(0);
    get_path(cmd, d);
}
// //void    exec_parent(char **cmd, t_data *d)
// {
//     //puts("caca");
// }

void exec_simple(char  **cmd, t_data *d)
{
    g_sig.prog = 1;
    g_sig.pid = fork();
    if (g_sig.pid == -1)
	  	opening_error("Fork");
    else if (g_sig.pid == 0)
        exec_child(cmd, d);
    else
    {
        waitpid(-1, &g_sig.status, 0);
        free_array(cmd);
    }
    if (WIFEXITED(g_sig.status))
        g_sig.status = WEXITSTATUS(g_sig.status);
    g_sig.prog = 0;
    //printf("%i\n", g_sig.status);
    
}

