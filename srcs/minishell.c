/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucrece <lucrece@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/16 10:20:02 by lucrece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Ajoute les fonctions une a une a l'historique (utile pour la suite).
*/
t_sig g_sig;
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
