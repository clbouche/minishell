/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/14 15:36:47 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_dlist	*init_list(t_dlist *list)
{
	list = malloc(sizeof(t_dlist));
	if (!list)
		exit(0);
	list->end = NULL;
	list->begin = NULL;
	list->len = 0;
	return (list);
}

int	init(t_env *env, t_dlist *list)
{
	list = init_list(list);
	env = malloc(sizeof(t_env *));
	env->path = getenv("PATH");
	env->paths = ft_split(env->path, ':');
	return (0);
}
