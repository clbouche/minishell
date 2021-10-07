/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:22:28 by claclou           #+#    #+#             */
/*   Updated: 2021/10/07 15:55:47 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_redir(char **input, int i, t_data *data)
{
	char	*str;
	int		j;

	str = *input;
	j = i;
	if (str[i] == '>' && str[i + 1] != '>')
	{
		//redir_to(str, i, input, data);
		printf(">");
	}
	else if (str[i] == '>' && str[i + 1] == '>')
	{
		//redir_to_append(str, i, input, data);
		printf(">>");
	}
	else if (str[i] == '<' && str[i + 1] != '<')
	{
		//redir_from(str, i, input, data);
		printf("<");
	}
	else if (str[i] == '<' && str[i + 1] == '<')
	{
		//other_redir(str, i, input, data);
		printf("<<");
	}
}

int	manage_redir(char **input, t_data	*data)
{
	int		i;
	char	*str;

	i = 0;
	str = *input;
	while (str[i++])
	{
		if (str[i] == '>' || str[i] == '<')
		{
			check_redir(input, i, data);
			return (1);
		}
	}
	return (0);
}
