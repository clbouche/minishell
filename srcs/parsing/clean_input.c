/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:48:26 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/16 12:22:17 by clbouche         ###   ########.fr       */
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
			while(*src && *src != quote)
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
	int		j;
	char	quote;

	i = 0;
	j = 0;
	while(line[j++])
	{
		if (ft_iswhitespace(line[j]) && ((ft_iswhitespace(line[j + 1]) || line[j + 1] == '\0')))
			j++;
		if (line[j] == '"' ||line[j] == '\'')
		{
			quote = line[j++];
			while (line[j++] != quote)
			{
				if (line[j] == '\0')
					return (-1);
				i++;
			}
			i += 2;
		}
		i++;
	}
	return (i);
}

char	*clean_input(char *line)
{
	int 	len;
	char	*input;
	int 	i;
	
	i = 0;
	while (line[i] && ft_iswhitespace(line[i]))
		i++;
	len = input_len(line);
	if (len == -1)
	{
		free(line);
		return(NULL);
	}
	input = malloc(sizeof(char) * (len + 1));
	if (!input)
	 	exit(EXIT_FAILURE);
	copy_input(input, line);
	free(line);
	return(input);
}


