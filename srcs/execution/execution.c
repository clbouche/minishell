/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:02:21 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/10/07 11:37:26 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void parse_exec(char *line, t_data *d)
{
    char **cmd;
    int ret;

    ret = 0;
    cmd = ft_split(line, ' ');
    // while(cmd[ret])
    // {
    // 	printf("%s\n", cmd[ret]);
    // 	ret ++;
    // }
    // ret = 0;
    ret = is_builtins(cmd);
    //printf("%i\n", ret);
    if (ret != FAILURE)
        exec_builtin(cmd, d);
    else
    {
        exec_simple(cmd, d);
    }		
    // else
    // {
    // 	char **paths;
    // 	int i;
    // 	paths = get_path(cmd, &d);
    // 	while(paths[i])
    // 	{
    // 		printf("%s\n", paths[i]);
    // 		i++;
    // 	}
    // }
    
    // get_path(cmd, envp);
    
    //printf("\n%i", ret);
}