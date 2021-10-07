/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/07 15:44:15 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_sig g_signal;

t_list	*init(t_data *d, char **envp)
{
	
	d->env = NULL;
	ft_memset(d, 0, sizeof(d));
	d->env = get_env(d, envp);
	return (d->env);
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