/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:36:42 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/11/29 10:40:34 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*  KILL(int pid, int signal)
**  if pid > 0 signal si sent to pid
**  if pid == 0 signal is sent to the entire process group
**  @param signo Signal code
**  @return void
*/

void	sig_heredoc(int signo)
{
	(void)signo;
	ft_putstr_fd("\b\b  \b\b", 1);
}

void	sig_int(int signo)
{
	if (signo == SIGINT)
	{
		g_sig.status = 130;
		//debug("g_sig.pid [%d]", g_sig.pid);
		//debug("g_sig.prog [%d]", g_sig.prog);
		if (g_sig.prog == 0)
		{
			ft_putchar_fd('\n', 1);
			//rl_replace_line("", 1);
			rl_on_new_line();
			rl_redisplay();
		}
		else if (g_sig.prog == 1)
		{
			g_sig.sigint = 1;
			rl_redisplay();
		}
	}
}

void	sig_quit(int signo)
{
	if (signo == SIGQUIT)
	{
		g_sig.status = 131;
		if (g_sig.prog == 1)
		{
			g_sig.sigquit = 1;
			kill(g_sig.pid, SIGQUIT);
			ft_putstr_fd("Quit (core dumped)\n", 2);
		}
		else
			ft_putstr_fd("\b\b  \b\b", 1);
	}
}
