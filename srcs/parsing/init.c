/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/14 12:31:59 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_sig g_signal;

t_list	*init(t_data *d, char **envp)
{
	int shlvl;

	d->env = NULL;
	shlvl = ft_atoi(getenv("SHLVL") + 1);
	ft_memset(d, 0, sizeof(d));
	d->env = get_env(d, envp);
	d->env = set_lvl(d->env, shlvl);
	return (d->env);
}
