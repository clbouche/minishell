/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/08 16:52:57 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_list(t_list *list)
{
	list = malloc(sizeof(t_list));
	list->content = NULL;
}

int	init(t_env *env, t_list *list)
{
	init_list(list);
	env = malloc(sizeof(t_env *));
	env->path = getenv("PATH");
	env->paths = ft_split(env->path, ':');
	return (0);
}