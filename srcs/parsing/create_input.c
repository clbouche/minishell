/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:29:44 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/04 14:04:00 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_input(char *dst, char *src)
{
	char	quote;

	while(*src)
	{
		if (ft_iswhitespace(*src) && (ft_iswhitespace(*(src + 1)) || *(src + 1) == '\0'))
			src++;
		if (*src == '"' || *src == '\'')
		{
			*(dst++) = *src;
			quote = *(src++);
			while(*src != quote)
				*(dst)++ = *(src)++;
			*(dst++) = *(src++);
		}
		else
			*(dst++) = *(src++);
		//gerer les chars interdits
	}
	*dst = '\0';
}

int		input_len(char *line)
{
	int		i;
	char	quote;

	i = 0;
	while(*line)
	{
		if (ft_iswhitespace(*line) && (ft_iswhitespace(*(line + 1)) || *(line + 1) == '\0'))
			line++;
		if (*line == '"' || *line == '\'')
		{
			quote = *(line++);
			while (*line && *line != quote)
			{
				i++;
				line++;
			}
			line++;
			i += 2;
		}
		else if (line++)
			i++;
	}
	return (i);
}

char	*create_input(char *line)
{
	int 	len;
	char	*input;

	while (*line && ft_iswhitespace(*line))
		line++;
	len = input_len(&*line);
	if (len == 0)
		return(NULL);
	input = malloc(sizeof(char) * (len + 1));
	copy_input(input, line);
	return(input);
}