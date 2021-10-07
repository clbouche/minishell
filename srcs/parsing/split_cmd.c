/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:32:10 by claclou           #+#    #+#             */
/*   Updated: 2021/10/07 15:58:19 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*next_cmd(char *str)
{
	char	quote;

	while (*(str++))
	{
		if (*str == '"' || *str == '\'')
		{
			quote = *(str++);
			while (*str != quote)
				str++;
		}
		if (*str == ' ')
			return (str + 1);
	}
	return (str);
}

void	copy_arg(char *src, char *dst, char quote)
{
	while (*src != ' ' && *src)
	{
		if (*src == '\'')
		{
			quote = *src++;
			while (*src != quote)
				*dst++ = *src++;
			src++;
		}
		else if (*src == '"')
		{
			quote = *(src++);
			while (*src != quote)
			{
				if (*(src + 1) == '$')
					src++;
				*dst++ = *src++;
			}
			src++;
		}
		else
			*dst++ = *src++;
	}
	*dst = '\0';
}

char	*split_args(char *str)
{
	int		len;
	char	*arg;
	char	quote;

	quote = 0;
	len = ft_strlen(str);
	arg = malloc(sizeof(char) * (len + 1));
	if (!arg)
		exit(EXIT_FAILURE);
	copy_arg(str, arg, quote);
	return (arg);
}

int		count_args(char *line)
{
	int		i;
	char	quote;

	i = 1;
	while (*line++)
	{
		if (*line == '"' || *line == '\'')
		{
			quote = *line++;
			while (*line != quote)
				line++;
		}
		if (*line == ' ')
			i++;
	}
	return (i);
}

char	**split_cmd(char *line)
{
	char	**cmd;
	int		i;
	int		count;

	i = 0;
	count = count_args(line);
	cmd = malloc(sizeof(char *) * (count + 1));
	if (!cmd)
		exit(EXIT_FAILURE);
	while (i < count)
	{
		cmd[i++] = split_args(line);
		line = next_cmd(line);
	}
	cmd[i] = NULL;
	return (cmd);
}