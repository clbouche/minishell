/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:36:42 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/10/13 16:05:16 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void sig_quit(void)
// {
//     ret
// }
// static void sig_int(void)
// {
//     g_sig.status = 130;
// 	if (g_sig.prog == 0)
// 	{
// 		ft_putstr_fd("\n", 0);
// 		rl_on_new_line();
// 		rl_replace_line("", 0);
// 		rl_redisplay();
// 	}
// 	else
// 	{
// 		ft_putchar_fd('\n', 0);
// 	}
// }

// void    sig_handler(int sig)
// {
//     if (sig == SIGQUIT)
//         sig_quit();
//     if (sig == SIGINT)
//         sit_int();
// }