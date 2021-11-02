/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/02 17:57:15 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sig g_sig;

void	check_redir(char *line, t_data *data)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '<' || line[i] == '>')
			manage_redir(line, i, data);
		i++;
	}
}

/*
** Transition d'un input propre vers l'execution
*/
int	parse_to_exec(char *input, t_data *data)
{
	char **cmd;

	input = create_input(input);
	printf("input 2 : [%s]\n", input);
	check_redir(input, data);
	input = create_input(input);
	printf("input 3 : [%s]\n", input);
	cmd = split_cmd(input);
	free(input);
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
	char	*line;
	char	*input;

	while (1)
	{
		line = readline("🍄 MINISHELL 🍄 : ");
		//line = readline("");
		if (line == NULL)
			line = ft_strdup("exit");
		if (*line)
		{
			manage_history(line);
			input = create_input(line);
			printf("input 1 : [%s]\n", input);
			parser(input, data);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argv;
	//rl_outstream = stderr;
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