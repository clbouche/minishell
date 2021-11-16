/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/16 12:21:11 by clbouche         ###   ########.fr       */
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
	
	input = clean_input(input);
	input = check_redir(input, data);
	if (!input || input[0] == 0)
		return (1);
	input = clean_input(input);
	cmd = split_cmd(input);
	ft_memdel(&input);
	// printf("d->std_in == %i\n", data->std_in);
	// printf("d->std_out == %i\n", data->std_out);
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
	char 	*line;
	char	*input;
	
	line = NULL;
	while (1)
	{
		line = readline("🍄 MINISHELL 🍄 : ");
		if (line == NULL)
			line = ft_strdup("exit");
		if (line != NULL)
		{
			manage_history(line);
			input = clean_input(line);
			if (input == NULL)
				ft_putstr_fd("unclosed quotes\n", 1);
			else if (input[0])
			{
				count_redir(input, data);
				parser(input, data);
			}
			else
				free(input);
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