/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/21 15:06:58 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern	t_sig g_signal;

void	init_datas(t_data *data)
{
	data->std_in = 0;
	data->std_out = 1;
}

t_list	*init(t_data *data, char **envp)
{
	data->env = NULL;
	ft_memset(data, 0, sizeof(data));
	data->env_len = 0;
	data->env = get_env(data, envp);
	return (data->env);
}

