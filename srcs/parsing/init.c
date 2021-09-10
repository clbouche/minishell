/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/09 11:46:53 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_dlist	*init_list(t_dlist *list)
{
	list = malloc(sizeof(t_dlist));
	if (!list)
		exit(0);
	list->begin = NULL;
	list->end = NULL;
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