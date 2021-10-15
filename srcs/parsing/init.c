/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/15 17:16:22 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern	t_sig g_signal;

void	init_datas(t_data *data)
{
	data->input = 0;
	data->ouput = 1;
}

t_list	*init(t_data *data, char **envp)
{
	data->env = NULL;
	ft_memset(data, 0, sizeof(data));
	data->env = get_env(data, envp);
	return (data->env);
}

