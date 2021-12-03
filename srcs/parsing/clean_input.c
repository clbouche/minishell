/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:48:26 by clbouche          #+#    #+#             */
/*   Updated: 2021/12/03 10:14:20 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_input(char *dst, char *src)
{
	char	quote;

	while (*src)
	{
		if (ft_iswhitespace(*src) && (ft_iswhitespace(*(src + 1))
				|| *(src + 1) == '\0'))
			src++;
		else if (*src == '"' || *src == '\'')
		{
			*(dst++) = *src;
			quote = *(src++);
			while (*src != quote)
				*(dst)++ = *(src)++;
			*(dst++) = *(src++);
		}
		else
			*(dst++) = *(src++);
	}
	*dst = '\0';
}

int	manage_quote(char *line, int i)
{
	char	quote;

	quote = *(line++);
	while (*line && *line != quote)
	{
		i++;
		line++;
	}
	if (!*line)
		return (-1);
	return (i);
}

int	input_len(char *line)
{
	int		i;

	i = 0;
	while (*line)
	{
		if (ft_iswhitespace(*line) && ((ft_iswhitespace(*(line + 1))
					|| *(line + 1) == '\0')))
			line++;
		else if (*line == '"' || *line == '\'')
		{
			i = manage_quote(line, i);
			line++;
			i += 2;
		}
		else if (line++)
			i++;
	}
	return (i);
}

char	*clean_input(char *line)
{
	int		len;
	char	*input;
	char	*tmp;

	tmp = line;
	if (!line)
		return (NULL);
	while (*line && ft_iswhitespace(*line))
		line++;
	len = input_len(line);
	if (len == -1)
		return (0);
	input = malloc(sizeof(char) * (len + 1));
	if (!input)
		exit(EXIT_FAILURE);
	copy_input(input, line);
	free(tmp);
	return (input);
}
