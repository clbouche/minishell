/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/09 10:26:33 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	display_prompt()
{
	char *prompt;
	size_t	len;
	size_t	count_slash;
	
	if ((prompt = getenv("USER")))
	{
		ft_putstr_fd("\033[31;1m", 1);
		ft_putstr_fd(prompt, 1);
		ft_putstr_fd("\033[1m:", 1);
		//free(prompt);
	}
	prompt = getcwd(NULL, 0);
	len = ft_strlen(prompt);
	count_slash = 0;
	while (--len && count_slash < 3)
		if (prompt[len] == '/')
			count_slash++;
	ft_putstr_fd("\e[1;32m", 1);
	while (prompt[++len])
		ft_putchar_fd(prompt[len], 1);
	ft_putstr_fd("$\e[0m ", 1);
	free(prompt);
}

int main(int argc, char **argv, char **envp)
{
	char *line;
	char *prompt;
	t_env	*env;
	t_list *list;

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
	//fonctions de free
	return (0);
}