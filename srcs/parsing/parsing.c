/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:02 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/06 10:30:43 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	manage_dollars(char *line, t_data *data)
{
	//verifier si a la suite '?' ou pas
	// 	-> si oui, envoyer a check history 
	// 	-> si non, checker la variable 
	// pas tout compris
}

void	manage_pipe(char *line, t_data *data)
{
	//faire une copie du reste de la ligne 
	//executer le debut de la ligne jusqu'au pipe
	//revenir au parser avec le reste de la ligne
}

char	*manage_quotes(char *line, t_data *data)
{
	int i;

	i = 0;
	printf(" line[i] : %s\n", line);
	while (line[i] != '"')
	{
		if (line[i] == '$')
			printf("manage $(expand)\n");
		i++;
	}
	return (&line[i + 1]);
}

void	parser(char *line, t_data *data)
{
	int	i;

	i = 0;
	while(line[i])
	{
		if (line[i] == '"')
			line = manage_quotes(&line[i + 1], data);
		if (line[i] == '|')
			manage_pipe(&line[i + 1], data);
		if (line[i] == '$')
			manage_dollars(&line[i + 1], data);
		i++;
	}
	//execute (gerer les redirections dedans)
}
