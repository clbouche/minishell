/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:49:47 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/10/26 15:15:00 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_sig sig;
// static void cmd_with_path(char **cmd)
// {
//     char *path;
//     char *cmd_name;
//     int i;
//     int b;
    
//     i = 0;
//     b = 0;
//     path = NULL;
//     cmd_name = NULL;
//     if (cmd[0][i] == '.' && cmd[0][i + 1] == '/')
//     {
//         path = ft_strcat(getcwd(path, SIZE_MAX), "minishell");
//         printf("path == %s\n", path);
//         //if (access())
//     }
    
//     // else if (cmd[0][i] == '/')
//     // {
//     //     while (cmd[0][i])
//     //     {
//     //         if(cmd[0][i] == ' /')
//     //             b++;
//     //         i++;
//     //     }
//     //     i = 0;
//     //     while(b > 0 && cmd[0][i])
//     //     {
//     //         if(cmd[0][i] == ' /')
//     //             b--;
//     //         i++;
//     //     }
//     //     path = ft_substr(cmd[0], 0, i);
// }

void    exec_child(char **cmd, t_data *d)
{
    char *bin;
    char **paths;

    paths = get_path(d);
    bin = find_bin(paths, cmd);
    exec_bin(cmd, bin, d);
}

void exec_simple(char  **cmd, t_data *d)
{ 
    g_sig.prog = 1;
    // char path[MAX];
    // if (cmd[0][0] == '.' && cmd[0][1] == '/')
    // {
    //     path = getcwd(path, MAX);
    //     printf("path == %s\n", path);
    //     path = ft_strcat(path, "minishell");
    //     printf("path == %s\n", path);
    //     //if (access())
    // }
    g_sig.pid = fork();
    if (g_sig.pid == -1)
	  	puts("error_pid attention oublie pas dexit proprement");
    if (g_sig.pid == 0)
        exec_child(cmd, d);
    else
    {
        waitpid(-1, &g_sig.status, 0);
        free_array(cmd);
    }
    if (WIFEXITED(g_sig.status))
        g_sig.status = WEXITSTATUS(g_sig.status);
    g_sig.prog = 0;
}
