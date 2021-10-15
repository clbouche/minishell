/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/15 17:20:41 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Ajoute les fonctions une a une a l'historique (utile pour la suite).
*/
void	manage_history(char *input)
{
	if (input)
		add_history(input);
}

void	minishell_loop(t_data *data)
{
	char	*line;
	char	**cmd;
	
	
	while (1)
	{
		line = readline("🍄 MINISHELL 🍄 : ");
		if (line == NULL)
				break;
		manage_history(line);
		cmd = parser(line, data);
		execute(cmd, data);
		//parse_exec(line, &d);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argv;
	if (argc == 1)
	{
		signal(SIGINT, &sig_handler);
		signal(SIGQUIT, &sig_handler);
		data.env = init(&data, envp);
		init_datas(&data);
		minishell_loop(&data);
	}
	ft_putstr_fd("exit\n", 1);
	return (g_sig.status);
}
