/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:02 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/13 18:26:31 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*PRINTF A SUPPR*/

char	**put_token(char **line)
{
	int i;

	i = -1;
	/*while (line[i++] != NULL)
	{
		printf("line[%d] = : %s\n", i, line[i]);
	}*/
	return(line);
}

void	parser(char *line, t_dlist *list)
{
	char **split_line;

	if (line)
	{
		split_line = ft_split(line, ' ');
		put_token(split_line);
	}
	else 
		exit(0);
}