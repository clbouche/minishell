/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:32:10 by claclou           #+#    #+#             */
/*   Updated: 2021/11/10 11:50:32 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** Recupere le prochain argument.
*/

static char	*next_cmd(char *str)
{
	char	quote;

	while (*str++)
	{
		if (ft_iswhitespace(*str) && (ft_iswhitespace(*(str + 1)) || *(str + 1) == '\0'))
			str++;
		if (*str == '"' || *str == '\'')
		{
			quote = *(str++);
			while (*str && *str != quote)
				str++;
		}
		if ((ft_iswhitespace(*str) && (!ft_iswhitespace(*(str + 1)) || !(*(str + 1) == '\0')))
			|| (*str == '|') || (*str == '$'))
			return (str + 1);
	}
	return (str);
}

/*
** Recupere l'arg pour le placer dans le tableau.
*/

void	copy_arg(char *src, char *dst, char quote)
{
	while (*src && *src != ' ' && *src != '|' && *src != '$')
	{
		if (*src == '\'' || *src == '"')
		{
			quote = *src++;
			while (*src && *src != quote)
				*dst++ = *src++;
		}
		else
			*dst++ = *src++;
	}
	*dst = '\0';
}

/*
** Determiner chaque arg.
*/

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

/*
** Permet de faire le malloc.
*/

size_t	count_args(char *line)
{
	size_t		i;
	char	quote;

	i = 1;
	while (*line++)
	{
		if (ft_iswhitespace(*line) && (ft_iswhitespace(*(line + 1)) || *(line + 1) == '\0'))
			line++;
		if (*line == '"' || *line == '\'')
		{
			quote = *line++;
			while (*line && *line != quote)
				line++;
		}
		if ((ft_iswhitespace(*line) && (!ft_iswhitespace(*(line + 1)) || !(*(line + 1) == '\0')))
			|| (*line == '|' ) || (*line == '$'))
			i++;
	}
	return (i);
}


void	print_cmd(char **cmd)
{
	int	i;

	i = 0;
	while(cmd[i])
	{
		printf("cmd[%i] : [%s]\n", i, cmd[i]);
		i++;
	}
}

/*
** Creer le tableau de char * des arguments constituant la ligne de commande.
*/

char	**split_cmd(char *line)
{
	char	**cmd;
	size_t		i;
	size_t		count;

	i = 0;
	if (!line)
		return (NULL);
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
	//print_cmd(cmd);
	return (cmd);
}
