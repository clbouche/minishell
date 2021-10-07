/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/07 15:54:41 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	manage_history(char *input)
{
	if (input)
		add_history(input);
}

void	minishell_loop(t_data *data)
{
	char	*line;
	char	**cmd;
	
	while (1) //changer pour dire tant que pas EOF ou ctrl+D ou exit ou ? 
	{
		line = readline("🍄 MINISHELL🍄 : ");
		manage_history(line);
		cmd = parser(line, data);
		execute(cmd, data);
	}
}

int main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc == 1)
	{
		//ajouter le signal ici 
		//initialiser les datas : sortie standard, etc..
		data.env = init(&data, envp);
		init_datas(&data);
		minishell_loop(&data);

	}
	return (0);
}
