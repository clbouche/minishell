/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/10 11:09:25 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*display_prompt()
{
	char *prompt;
	char *add;

	prompt = "\001\033[31;1m\002 ";
	add = "🍄 MINISHELL🍄 : ";
	prompt = ft_strjoin(prompt, add);
	add = "\001\e[1;32m\002";
	prompt = ft_strjoin(prompt, add);
	add = getcwd(NULL, 0);
	prompt = ft_strjoin(prompt, add);
	add = "$  ";
	prompt = ft_strjoin(prompt, add);
	char *reset_cmd = tgetstr("me", NULL);
	tputs(reset_cmd, 1, putchar);
	return (prompt);
}

int main(int argc, char **argv, char **envp)
{
	char *line;
	char *prompt;
	t_env	*env;
	t_dlist *list;

	if (argc == 1)
	{
		init(env, list);
		while (1) //changer pour dire tant que pas EOF ou ctrl+D ou exit ou ? 
		{
			prompt = display_prompt();
			line = readline(prompt);
			parser(line, list);
		}
	}
	else
		exit(0);
	free(line);
	return (0);
}