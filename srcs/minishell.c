/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/23 12:31:56 by ldes-cou         ###   ########.fr       */
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
			g_sig.sigint = 0;
			manage_history(line);
			input = clean_input(line);
			if (input == NULL)
				ft_putstr_fd("unclosed quotes\n", 1);
			else if (input[0])
			{
				count_redir(input, data);
				count_childs(input, data);
				malloc_pid_array(data);
				data->std_out = dup(1);
				data->std_in = dup(0);	
				parser(input, data);
				restore_fds(data);
				printf("data->pipes %i\n", data->pipes);
				while(data->pipes >= 0)
				{
					waitpid(-1, &g_sig.status, 0);
					data->pipes--;
				}
				//puts("pipi");
				// while(data->pipes > 0)
				// {
				// 	puts("caca");
				// 	debug("waiting for : [%d]", data->pid_array[data->pid]);
				// 	waitpid(data->pid_array[data->pid], &g_sig.status, 0);
				// 	data->pipes--;
				// 	data->pid--;
				// }
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
		signal(SIGINT, &sig_int);
		signal(SIGQUIT, &sig_quit);
		data.env = init_env(&data, envp);
		init_datas(&data);
		minishell_loop(&data);
	}
	return (g_sig.status);
}