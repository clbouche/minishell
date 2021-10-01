/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/01 11:04:16 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*init(t_data *d, char **envp)
{	
	
	d->env = NULL;
	ft_memset(d, 0, sizeof(d));
	// printf("rret ==%i\n", d->ret);
	// printf("%i\n", d->env_len);
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