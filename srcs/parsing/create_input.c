/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:29:44 by clbouche          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/10 17:00:18 by ldes-cou         ###   ########.fr       */
=======
/*   Updated: 2021/11/10 14:40:29 by clbouche         ###   ########.fr       */
>>>>>>> end_parsing
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
		else if (*src == '"' || *src == '\'')
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
	while(*line && line)
	{
		if (ft_iswhitespace(*line) && ((ft_iswhitespace(*(line + 1)) || *(line + 1) == '\0')))
			line++;
		if (*line == '"' || *line == '\'')
		{
			quote = *(line++);
			while (*line && *line != quote)
			{
				i++;
				line++;
			}
			if (!*line)
				return (-1);
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
	char	*tmp;

	tmp = line;
	if (!line)
		return (NULL);
	while (*line && ft_iswhitespace(*line))
		line++;
	len = input_len(line);
	if (len == -1)
		return(0);
	input = malloc(sizeof(char) * (len + 1));
	if (!input)
		exit(EXIT_FAILURE);
	copy_input(input, line);
	free(tmp);
	return(input);
}
