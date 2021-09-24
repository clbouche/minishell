/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/24 14:43:09 by clbouche         ###   ########.fr       */
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
	//puts("ft_export_var");
	//ft_export_var(env, "EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE", "|||||||||||||||||||||||||||||||||||||||");
	//puts("ft_export");
	ft_export(env);
	env = ft_unset(env, "LANGUAGE");
	//ft_export(env);
	ft_env(env);
	//ft_env(env);
	//ft_env(env);
}
	//env->path = getenv("PATH");
	//env->paths = ft_split(env->path, ':');
	//env = malloc(sizeof(t_env *));