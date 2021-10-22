/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:54:08 by claclou           #+#    #+#             */
/*   Updated: 2021/10/22 14:29:50 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_char(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == ';' || c == ' ')
		return (FALSE);
	return(SUCCESS);
}

/*
** Utile pour le malloc.
*/
int	recup_file_len(char *str)
{
	int		i;
	char	quote;

	i = 0;
	while(str[i] == ' ')
		i++;
	while(str[i] && check_char(str[i]) == SUCCESS)
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			quote = str[i];
			i++;
			while(str[i] && str[i] != quote)
				i++;
		}
		else
			i++;
	}
	return (i);
}

/*
** Permet de nommer le fichier ou d'aller chercher un fichier.
*/
char	*recup_filename(char *str)
{
	int		i;
	int		j;
	char	*file_name;
	char	quote;

	i = 0;
	j = 0;
	file_name = malloc(sizeof(char) * (recup_file_len(str) + 1));
	while(str[i] == ' ')
		i++;
	while(str[i] && check_char(str[i]) == SUCCESS)
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			quote = str[i];
			i++;
			while(str[i] && str[i] != quote)
				file_name[j++] = str[i++];
			file_name[j] = '\0';
			return (file_name);
		}
		else
			file_name[j++] = str[i++];
	}
	file_name[j] = '\0';
	return (file_name);
}
