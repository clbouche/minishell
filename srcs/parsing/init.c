/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/11 11:25:23 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern	t_sig g_signal;

void	init_datas(t_data *data)
{
	data->std_in = 0;
	data->std_out = 1;
	data->file_out = 0;
	data->file_in = 0;
	data->have_path = false;
	getcwd(data->pwd, MAX);
	data->piped = false;
	data->pipe = false;
	data->count_redir_in = 0;
	data->count_redir_out = 0;
	data->count_redir_append = 0;
	data->count_redir_heredoc = 0;
	data->redir_in = false;
	data->redir_out = false;
	data->bad_redir = false;
}

t_list	*init(t_data *data, char **envp)
{
	data->env = NULL;
	ft_memset(data, 0, sizeof(data));
	data->env_len = 0;
	data->env = get_env(data, envp);
	return (data->env);
}

