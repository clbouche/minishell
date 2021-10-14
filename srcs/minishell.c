/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/14 12:31:26 by ldes-cou         ###   ########.fr       */
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
		//ajouter le signal ici 
		d.env = init(&d, envp);
		while (1) //changer pour dire tant que pas EOF ou ctrl+D ou exit ou ? 
		{
			//line = exit ? break/exit
			line = readline("🍄 MINISHELL🍄 : ");
			add_history(line);
			//write_history("history.txt");
			parse_exec(line, &d);
			
			//parser(line);
			//execute(list) 
			//faire un parsing qui renvoie la liste chaînée traité 
		}
	}
	else
		exit(SUCCESS);

}
