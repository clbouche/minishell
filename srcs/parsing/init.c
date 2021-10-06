/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/06 10:07:02 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_datas(t_data *data)
{
	data->input = 0;
	data->ouput = 1;
}

t_list	*init(t_data *d, char **envp)
{	
	t_list *env;
	
	ft_memset(d, 0, sizeof(d));
	d->env = get_env(d->env, envp);
	
	return (d->env);
}
