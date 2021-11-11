/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/11 14:33:02 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sig g_sig;

/*
** Transition d'un input propre vers l'execution
*/
int	parse_to_exec(char *input, t_data *data)
{
	char **cmd;

	input = create_input(input);
	input = check_redir(input, data);
	if (!input || input[0] == 0)
		return (1);
	input = create_input(input);
	cmd = split_cmd(input);
	free(input);
	input = NULL;
	execute(cmd, data);
	return (0);
}

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
	static char	*line = (char *) NULL;
	char	*input;
	
	while (1)
	{
		if (line)
			line = (char *) NULL;
		rl_catch_signals = 0;
		line = readline("🍄 MINISHELL 🍄 : ");
		//printf("line === %s\n", line);
		if (!line)
			line = ft_strdup("exit");
		if (line != NULL)
		{
			manage_history(line);
			input = create_input(line);
			if (input == 0)
			{
				ft_putstr_fd("unclosed quotes", 1);
				return ;
			}
			count_redir(input, data);
			parser(input, data);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	
	(void)argv;
	puts("hello you, welcome !");
	if (argc == 1)
	{
		signal(SIGINT, &sig_handler);
		signal(SIGQUIT, &sig_handler);
		data.env = init(&data, envp);
		init_datas(&data);
		minishell_loop(&data);
	}
	return (g_sig.status);
}