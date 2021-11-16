/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_fds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 11:36:04 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/11/15 15:00:20 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_fds(t_data *d)
{
	d->redir->r_out = true;
	dup2(d->fds[1], 1);
	d->file_out = d->fds[1];
	close(d->fds[0]);
	close(d->fds[1]);
}

void switch_fds(t_data *d)
{
	d->redir->r_in = true;
	dup2(d->fds[0], 0);
	d->file_in = d->fds[0];
	close(d->fds[0]);
	close(d->fds[1]);
}

void  close_fds(t_data *d)
{
	//static int close_fd = 1;
	if (d->redir->r_out == true || d->piped == true)
	{
		//write(2, "\n===close_out\n", 13);
		close(d->file_out);
		//d->std_out = 1;
		dup2(d->std_out, 1);
		close(d->std_out);
		d->redir->r_out = false;
	}
	if (d->redir->r_in == true || d->piped == true)
	{
		
		//write(2, "\n===close_in\n", 13);
		close(d->file_in);
		//d->std_in = 0;
		dup2(d->std_in, 0);
		close(d->std_in);
		d->redir->r_in = false;
	}
}