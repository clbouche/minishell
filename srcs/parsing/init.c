/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/14 16:25:42 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_sig g_signal;

// static char * increase_shlvl(void)
// {
// 	char *shlvl;
// 	int lvl;
	
// 	shlvl = getenv("SHLVL");
// 	lvl = ft_atoi(shlvl + 1);
// 	free(shlvl);
// 	shlvl = ft_itoa(lvl);
// }

t_list	*init(t_data *d, char **envp)
{

	d->env = NULL;
	
	ft_memset(d, 0, sizeof(d));
	d->env = get_env(d, envp);
	// d->env = set_lvl(d->env, shlvl);
	return (d->env);
}

