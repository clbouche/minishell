/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/06 10:07:02 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_sig g_signal;

void	init_datas(t_data *data)
{
	data->input = 0;
	data->ouput = 1;
}

t_list	*init(t_data *data, char **envp)
{
	
	data->env = NULL;
	ft_memset(data, 0, sizeof(data));
	data->env = get_env(data, envp);
	return (data->env);
}

// void tests(t_list *env, char **cmd)
// {
// //===> don't forget to free
// // 
// 	/**tests**/
// 	puts("ft_env"); 
// 	ft_env(env, d);
// 	//puts("ft_export_var");
// 	//ft_export_var(env, "EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE", "|||||||||||||||||||||||||||||||||||||||");
// 	//puts("ft_export");
// 	//ft_export(cmd);
// 	//ft_unset(cmd);
// 	//ft_export(cmd);
// 	//ft_env(env);
// 	//ft_env(env);
// 	//ft_env(env);
// }
