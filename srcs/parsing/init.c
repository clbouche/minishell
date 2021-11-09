/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/09 14:24:18 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern	t_sig g_signal;

void	init_datas(t_data *data)
{
	data->std_in = 0;
	data->std_out = 1;
	data->have_path = false;
	getcwd(data->pwd, MAX);
	data->count_redir_in = 0;
	data->count_redir_out = 0;
}

t_list	*init(t_data *data, char **envp)
{
	data->env = NULL;
	ft_memset(data, 0, sizeof(data));
	data->env_len = 0;
	data->env = get_env(data, envp);
	return (data->env);
}

