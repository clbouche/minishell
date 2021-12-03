/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:37:10 by clbouche          #+#    #+#             */
/*   Updated: 2021/12/03 09:57:20 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Utile pour le malloc.
*/
int	recup_file_len(char *str)
{
	int		i;
	char	quote;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] && check_char_file(str[i]))
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			quote = str[i];
			i++;
			while (str[i] && str[i] != quote)
				i++;
		}
		else
			i++;
	}
	return (i);
}

int	deal_with_quotes(char *str, char quote, int i, char *file_name)
{
	int	j;

	j = 0;
	quote = str[i];
	str[i++] = ' ';
	while (str[i] && str[i] != quote)
	{
		file_name[j++] = str[i];
		str[i++] = ' ';
	}
	return (j);
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

	quote = 0;
	j = 0;
	i = 0;
	file_name = malloc(sizeof(char) * (recup_file_len(str) + 1));
	while (str[i] == ' ')
		i++;
	while (str[i] && check_char_file(str[i]))
	{
		if (str[i] == '\'' || str[i] == '"')
			j = deal_with_quotes(str, quote, i, file_name);
		else
		{
			file_name[j++] = str[i];
			str[i++] = ' ';
		}
	}
	file_name[j] = '\0';
	return (file_name);
}
