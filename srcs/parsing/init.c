/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/15 13:52:28 by ldes-cou     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	init(char **envp, t_list *env, t_dlist *list)
{
	//env = malloc(sizeof(t_env *));
	//env->path = getenv("PATH");
	//env->paths = ft_split(env->path, ':');
	get_env(envp, env);
	return (0);
}
