/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/12 16:40:03 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_sig g_signal;

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
