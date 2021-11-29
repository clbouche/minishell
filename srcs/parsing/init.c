/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/29 15:47:35 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_redir(t_data *data)
{
	data->redir = malloc(sizeof(t_redir));
	if (!data->redir)
		perror("malloc");
	data->redir->count_in = 0;
	data->redir->count_out = 0;
	data->redir->count_append = 0;
	data->redir->count_heredoc = 0;
	data->redir->r_in = false;
	data->redir->r_out = false;
	data->redir->bad_r = false;
}

void	init_datas(t_data *data)
{
	g_sig.prog = 0;
	g_sig.status = 0;
	data->file_out = 0;
	data->file_in = 0;
	data->have_path = false;
	getcwd(data->pwd, MAX);
	data->piped = false;
	data->pipe = false;
	g_sig.heredoc = false;
	init_redir(data);
}

t_list	*init_env(t_data *data, char **envp)
{
	data->env = NULL;
	ft_memset(data, 0, sizeof(data));
	data->env_len = 0;
	data->env = get_env(data, envp);
	return (data->env);
}
