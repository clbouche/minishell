/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/12/01 12:19:25 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sig	g_sig;

/*
** Transition d'un input propre vers l'execution
*/
int	parse_to_exec(char *input, t_data *data)
{
	char	**cmd;

	input = clean_input(input);
	input = check_redir(input, data);
	input = clean_input(input);
	if (!input || input[0] == 0)
		return (1);
	cmd = split_cmd(input);
	ft_memdel(&input);
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

void	minishell_to_parser(char *line, t_data *data)
{
	char	*input;

	g_sig.prog = 0;
	manage_history(line);
	input = clean_input(line);
	if (input == NULL)
		ft_putstr_fd("unclosed quotes\n", 1);
	else if (input[0])
	{
		count_redir(input, data);
		count_childs(input, data);
		malloc_pid_array(data);
		save_std_fds(data);
		parser(input, data);
		restore_fds(data);
		wait_for_childs(data);
	}
	else
		free(input);
}

void	minishell_loop(t_data *data)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = readline("🍄 MINISHELL 🍄 : ");
		if (line == NULL)
			line = ft_strdup("exit");
		if (line != NULL)
			minishell_to_parser(line, data);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argv;
	puts("hello you, welcome !");
	if (argc == 1)
	{
		signal(SIGINT, &sig_int);
		signal(SIGQUIT, SIG_IGN);
		//signal(SIGPIPE, &sig_pipe);
		data.env = init_env(&data, envp);
		init_datas(&data);
		minishell_loop(&data);
	}
	return (g_sig.status);
}
