/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:29:58 by clbouche          #+#    #+#             */
/*   Updated: 2021/12/02 22:23:33 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Permet de determiner si le delimiteur a ete croise ou non.
** Le delimiteur doit constituer l'integralite de l'input lu. 
** Il ne doit pas juste "faire partie" de l'input.
*/

int	len_delimiter(char *str)
{
	int		i;
	int		len;
	char	quote;

	i = 0;
	len = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] && (str[i] == '"' || str[i] == '\''))
	{
		quote = str[i++];
		while (str[i + len] != quote)
			len++;
		i++;
	}
	else
	{
		while (str[i + len] && (str[i] != ' ' || str[i] != '\0'))
			len++;
	}
	return (len);
}

char	*define_quote_delimiter(char *str, char *delimiter)
{
	char	quote;
	int		i;
	int		j;

	i = 0;
	j = 0;
	quote = str[i];
	str[i++] = ' ';
	while (str[i] && str[i] != quote)
	{
		delimiter[j++] = str[i];
		str[i++] = ' ';
	}
	str[i] = ' ';
	delimiter[j] = '\0';
	return (delimiter);
}

char	*define_delimiter(char *str)
{
	int		i;
	int		j;
	char	*delimiter;

	i = 0;
	j = 0;
	delimiter = malloc(sizeof(char) * (len_delimiter(str) + 1));
	if (!delimiter)
		exit(EXIT_FAILURE);
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '"' || str[i] == '\'')
		return (define_quote_delimiter(&str[i], delimiter));
	else
	{
		while (str[i] && str[i] != ' ')
		{
			delimiter[j++] = str[i];
			str[i++] = ' ';
		}
	}
	delimiter[j] = '\0';
	return (delimiter);
}
