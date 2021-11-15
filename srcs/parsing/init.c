/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:54 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/15 09:49:03 by clbouche         ###   ########.fr       */
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
	data->std_in = dup(0);
	data->std_out = dup(1);
	data->file_out = 0;
	data->file_in = 0;
	data->have_path = false;
	getcwd(data->pwd, MAX);
	data->piped = false;
	data->pipe = false;
	init_redir(data);
}

t_list	*init(t_data *data, char **envp)
{
	data->env = NULL;
	ft_memset(data, 0, sizeof(data));
	data->env_len = 0;
	data->env = get_env(data, envp);
	return (data->env);
}

