/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/20 15:33:09 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*char	*display_prompt()
{
	char *prompt;
	char *add;


	prompt = "🍄 MINISHELL🍄 : ";
	prompt = ft_strjoin(RED, prompt);
	prompt = ft_strjoin(prompt, GREEN);
	add = getcwd(NULL, 0);
	prompt = ft_strjoin(prompt, add);
	//add = "$  ";
	//prompt = ft_strjoin(prompt, add);
	//prompt = ft_strjoin(prompt, RESET);
	// char *reset_cmd = tgetstr("me", NULL);
	// tputs(reset_cmd, 1, putchar);
	return (prompt);
}*/

int main(int argc, char **argv, char **envp)
{
	char *line;
	char *prompt;
	t_dlist *list;

	prompt = getcwd(NULL, 0);
	if (argc == 1)
	{
		init(envp, list);
		while (1) //changer pour dire tant que pas EOF ou ctrl+D ou exit ou ? 
		{
			//prompt = display_prompt();
			line = readline("🍄 MINISHELL🍄 : ");
			parser(line, list);
		}
	}
	else
		exit(0);
	free(line);
	return (0);
}
