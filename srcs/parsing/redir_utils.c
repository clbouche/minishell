/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:54:08 by claclou           #+#    #+#             */
/*   Updated: 2021/11/09 14:26:11 by claclou          ###   ########.fr       */
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
	while(str[i] == ' ')
		i++;
	while(str[i] && check_char_file(str[i]))
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
	while(str[i] && check_char_file(str[i]))
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

void		count_redir(char *line, t_data *data)
{
	while (*line)
	{
		//est ce que je dois differencier le type de redirection? -> a voir 
		if (*line == '<')
		{
			data->count_redir_in++;
			data->redir_in = true;
		}
		if (*line == '>')
		{
			data->count_redir_out++;
			data->redir_out = true;
		}
		line++;
	}
}

void	check_redir(char *line, t_data *data)
{
	int i;

	i = 0;
	while (line[i] && (data->redir_out == true || data->redir_in == true))
	{
		if (line[i] == '<' || line[i] == '>')
			manage_redir(line, i, data);
		i++;
	}
}