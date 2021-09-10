/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/10 09:41:01 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	display_prompt()
{
	char *prompt;
	size_t	len;
	size_t	count_slash;
	
	prompt = "🍄 MINISHELL🍄 :";
	ft_putstr_fd("\033[31;1m", 1);
	ft_putstr_fd(prompt, 1);
	prompt = getcwd(NULL, 0);
	len = ft_strlen(prompt);
	ft_putstr_fd("\e[1;32m", 1);
	ft_putstr_fd(prompt, 1);
	ft_putstr_fd("$\e[0m ", 1);
	free(prompt);
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
			display_prompt();
			line = readline(prompt);
			parser(line, list);
		}
	}
	else
		exit(0);
	free(line);
	return (0);
}