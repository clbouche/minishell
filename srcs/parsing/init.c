/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/16 11:00:44 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init(t_env *env)
{
	env = malloc(sizeof(t_env *));
	env->path = getenv("PATH");
	env->paths = ft_split(env->path, ':');
}
