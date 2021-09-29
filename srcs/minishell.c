/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/29 14:08:49 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*###SUPPRIMER WRITE HISTORY####*/

int main(int argc, char **argv, char **envp)
{
	char *line;
	char **cmd;
	t_data	data;
	int ret;

	ret = 0;
	cmd = NULL;
	if (argc == 1)
	{
		//ajouter le signal ici 
		//initialiser les datas : sortie standard, etc..
		data.env = init(&data, envp);
		while (1) //changer pour dire tant que pas EOF ou ctrl+D ou exit ou ? 
		{
			line = readline("🍄 MINISHELL🍄 : ");
			add_history(line);
			write_history("history.txt");
			parser(line, &data);
			//execute(cmd) 
		}
	}
			// cmd = ft_split(line, ' ');
			// ret = is_builtins(cmd);
			// if (ret != FAILURE)
			// 	exec_builtin(ret, cmd, &d);
			// get_path(cmd, envp);
			
			//printf("\n%i", ret);
			
			//parser(line);
			//execute(list) 
			//faire un parsing qui renvoie la liste chaînée traité 
	else
		exit(0);
	return (ret);
}
