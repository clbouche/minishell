/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:36:42 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/10/18 16:31:48 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*  KILL(int pid, int signal)
    if pid > 0 signal si sent to pid
    if pid == 0 signal is sent to the entire process group
*/
void sig_handler(int signo)
{
    if (signo == SIGINT)
    {
        g_sig.status = 130;
        if (g_sig.prog == 0)
        {
            ft_putchar_fd('\n', 1);
            rl_on_new_line();
		    rl_replace_line("", 0);
		    rl_redisplay();
        }
        else if (g_sig.prog == 1)
        {
            rl_redisplay();
        }
        
    }
    
    if (signo == SIGQUIT)
    {    
        if (g_sig.prog == 1)
        {
            g_sig.status = 131;
            kill(g_sig.pid, SIGQUIT);
        }
        ft_putstr_fd("\b\b  \b\b", 1);
    } 
}