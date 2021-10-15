/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/15 16:37:29 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//faire une fonction qui affiche le prompt
t_sig g_sig;

int main(int argc, char **argv, char **envp)
{
	char *line;
	t_data d;
	(void)argv;

	line = NULL;
	if (argc == 1)
	{
		d.env = init(&d, envp);
		while (1) //changer pour dire tant que pas EOF ou ctrl+D ou exit ou ? 
		{
			signal(SIGINT, &sig_handler);
			signal(SIGQUIT, &sig_handler);
			//line = exit ? break/exit
			line = readline("🍄 MINISHELL🍄 : ");
			add_history(line);
			//write_history("history.txt"); ==> faire une foction history append, pour creer un seul fichier hsty.txt
			if (line == NULL)
				break;
			parse_exec(line, &d);
			
			//parser(line);
			//execute(list) 
			//faire un parsing qui renvoie la liste chaînée traité 
		}
	}
	ft_putstr_fd("exit\n", 1);
	return (g_sig.status);
}
