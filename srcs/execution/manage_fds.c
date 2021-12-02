/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_fds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:36:04 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/12/01 18:17:38 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_std_fds(t_data *data)
{
	data->std_out = dup(1);
	data->std_in = dup(0);
}

void	pipe_out(t_data *d)
{
	close(d->fds[0]);
	d->redir->r_out = true;
	dup2(d->fds[1], 1);
	close(d->fds[1]);
}

void	pipe_in(t_data *d)
{
	close(d->fds[1]);
	d->redir->r_in = true;
	dup2(d->fds[0], 0);
	close(d->fds[0]);
}

void	restore_fds(t_data *d)
{
	if (d->redir->r_out == true)//|| d->piped == true)
	{
		close(d->file_out);
		dup2(d->std_out, 1);
		d->redir->r_out = false;
	}
	if (d->redir->r_in == true) //|| d->piped == true)
	{
		close(d->file_in);
		dup2(d->std_in, 0);
		d->redir->r_in = false;
	}
	if (d->std_out != 1)
		close(d->std_out);
	if (d->std_in != 0)
		close(d->std_in);
}
