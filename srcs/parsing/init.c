/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/21 10:17:56 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	init(char **envp, t_dlist *list)
{
	get_env(envp);
	
	return (0);
}
void tests(t_list *env)
{
//===> don't forget to free
// 
	/**tests**/
	puts("ft_env"); 
	ft_env(env);
	puts("ft_export_var");
	ft_export_var(env, "PAPOU", "vour");
	puts("ft_export");
	ft_export(env);
	ft_unset(env, "PAPOU");
	//ft_env(env);
}
	//env->path = getenv("PATH");
	//env->paths = ft_split(env->path, ':');
	//env = malloc(sizeof(t_env *));