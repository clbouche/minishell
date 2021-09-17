/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/17 12:00:22 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_path(t_env *path)
{
	path = malloc(sizeof(t_env *));
	path->path = getenv("PATH");
	path->paths = ft_split(path->path, ':');
}

void init_env(char **envp, t_list *env)
{
	get_env(envp, env);
}