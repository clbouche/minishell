/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/01 12:10:32 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*###SUPPRIMER WRITE HISTORY####*/

int main(int argc, char **argv, char **envp)
{
	char *line;
	char **cmd;
	int ret;
	t_data d;

	ret = 0;
	cmd = NULL;
	if (argc == 1)
	{
		//ajouter le signal ici 
		d.env = init(&d, envp);
		while (1) //changer pour dire tant que pas EOF ou ctrl+D ou exit ou ? 
		{
			line = readline("🍄 MINISHELL🍄 : ");
			add_history(line);
			write_history("history.txt");
			cmd = ft_split(line, ' ');
			while(cmd[ret])
			{
				printf("%s\n", cmd[ret]);
				ret ++;
			}
			ret = 0;
			ret = is_builtins(cmd);
			printf("%i\n", ret);
			if (ret != FAILURE)
				exec_builtin(ret, cmd, &d);
			else
			{
				get_path(cmd, &d);
			}		
			// else
			// {
			// 	char **paths;
			// 	int i;
			// 	paths = get_path(cmd, &d);
			// 	while(paths[i])
			// 	{
			// 		printf("%s\n", paths[i]);
			// 		i++;
			// 	}
			// }
			
			// get_path(cmd, envp);
			
			//printf("\n%i", ret);
			
			//parser(line);
			//execute(list) 
			//faire un parsing qui renvoie la liste chaînée traité 
		}
	}
	else
		exit(SUCCESS);
	return (ret);
}
