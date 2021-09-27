/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/27 14:40:17 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*###SUPPRIMER WRITE HISTORY####*/

int main(int argc, char **argv, char **envp)
{
	char *line;


	if (argc == 1)
	{
		//ajouter le signal ici 
		//init(envp);
		while (1) //changer pour dire tant que pas EOF ou ctrl+D ou exit ou ? 
		{
			line = readline("🍄 MINISHELL🍄 : ");
			add_history(line);
			write_history("history.txt");
			parser(line);
			//execute(list) 
			//faire un parsing qui renvoie la liste chaînée traité 
		}
	}
	else
		exit(0);
	return (0);
}
