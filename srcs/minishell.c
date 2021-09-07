/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/07 15:59:46 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*put_prompt()
{
	char *prompt;
	char *send;

	send = "minishell$  ";
	prompt = ft_strdup(send);
	return (prompt);
}

int main(int argc, char **argv, char **env)
{
	char *line;
	char *prompt;

	if (argc == 1)
	{
		//init();
		while (1)
		{
			//faire le parsing de la ligne envoye
			prompt = put_prompt();
			line = readline(prompt);
			parser(line);
		}
	}
	//fonctions de free
	return (0);
}