/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/29 15:58:43 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*init(t_data *d, char **envp)
{	
	t_list *env;
	
	ft_memset(d, 0, sizeof(d));
	d->env = get_env(d->env, envp);
	
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