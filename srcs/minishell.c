/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/16 11:00:45 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int argc, char **argv, char **envp)
{
	char *line;
	char *prompt;
	t_list	*env;
	t_dlist *list;

	if (argc == 1)
	{
		init(envp, env, list);
		init_env(envp, env);
		while (1) //changer pour dire tant que pas EOF ou ctrl+D ou exit ou ? 
		{
			//ajouter le signal ici 
			line = readline("🍄 MINISHELL🍄 : ");
			parser(line);
		}
	}
	else
		exit(0);
	return (0);
}
