/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/27 14:54:02 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	init(char **envp)
{
	get_env(envp);
	
	return (0);
}
// void tests(t_list *env)
// {
// //===> don't forget to free
// // 
// 	/**tests**/
// 	puts("ft_env"); 
// 	ft_env(env);
// 	//puts("ft_export_var");
// 	//ft_export_var(env, "EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE", "|||||||||||||||||||||||||||||||||||||||");
// 	//puts("ft_export");
// 	ft_export(env);
// 	env = ft_unset(env, "SHELL");
// 	ft_export(env);
// 	//ft_env(env);
// 	//ft_env(env);
// 	//ft_env(env);
// }