/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:36:42 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/10/15 16:21:56 by ldes-cou@st      ###   ########.fr       */
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
        ft_putchar_fd('\n', 1);
        ft_putstr_fd("🍄 MINISHELL🍄 : ", 1);
    }
    if (signo == SIGQUIT)
    {    
        if (g_sig.prog == 1)
        {
            g_sig.status = 131;
            kill(g_sig.pid, SIGQUIT);
        }
        ft_putstr_fd("\b\b  \b\bQuit (core dumped)\n", 1);
    } 
}