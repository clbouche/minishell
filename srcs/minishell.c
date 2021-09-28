/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/28 12:08:36 by ldes-cou@st      ###   ########.fr       */
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
			ret = is_builtins(cmd);
			if (ret != FAILURE)
				exec_builtin(ret, cmd, &d);
			// get_path(cmd, envp);
			
			//printf("\n%i", ret);
			
			//parser(line);
			//execute(list) 
			//faire un parsing qui renvoie la liste chaînée traité 
		}
	}
	else
		exit(0);
	return (ret);
}
