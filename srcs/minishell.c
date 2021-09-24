/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/24 11:51:24 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*###SUPPRIMER WRITE HISTORY####*/

int main(int argc, char **argv, char **envp)
{
	char *line;
	t_list	*list;

	if (argc == 1)
	{
		init_env(envp, list);
		while (1) //changer pour dire tant que pas EOF ou ctrl+D ou exit ou ? 
		{
			//ajouter le signal ici 
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
