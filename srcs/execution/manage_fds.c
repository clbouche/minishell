/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_fds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:36:04 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/11/07 14:57:54 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_fds(t_data *d)
{
	d->redir_out = true;
	dup2(d->fds[1], 1);
	d->file_out = d->fds[1];
	close(d->fds[0]);
	close(d->fds[1]);
}

void switch_fds(t_data *d)
{
	d->redir_in = true;
	dup2(d->fds[0], 0);
	d->file_in = d->fds[0];
	close(d->fds[0]);
	close(d->fds[1]);
}

void  close_fds(t_data *d)
{
	if (d->redir_out == true)
	{
		close(d->file_out);
		dup2(d->std_out, 1);
		close(d->std_out);
		d->redir_out = false;
	}
	if (d->redir_in == true)
	{
		close(d->file_in);
		dup2(d->std_in, 0);
		close(d->std_in);
		d->redir_in = false;
	}
}