/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:54:08 by claclou           #+#    #+#             */
/*   Updated: 2021/11/15 12:32:11 by clbouche         ###   ########.fr       */
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
			str[i++] = ' ';
			while(str[i] && str[i] != quote)
			{
				file_name[j++] = str[i];
				str[i++] = ' ';
			}
			file_name[j] = '\0';
			return (file_name);
		}
		else
		{
			file_name[j++] = str[i];
			str[i++] = ' ';
		}
	}
	file_name[j] = '\0';
	return (file_name);
}

void		count_redir(char *line, t_data *data)
{
	int i;
	int quote;

	i = 0;
	while (line[i])
	{
		if (line[i] == '"' || line[i] == '\'')
		{
			quote = line[i++];
			while(line[i] != quote)
				i++;
		}
		if (line[i] == '<' && line[i + 1] != '<')
		{
			data->redir->count_in++;
			data->redir->r_in = true;
		}
		else if (line[i] == '>' && line[i + 1] != '>')
		{
			data->redir->count_out++;
			data->redir->r_out = true;
		}
		else if (line[i] == '>' && line[i + 1] == '>')
		{
			data->redir->count_append++;
			data->redir->r_out = true;
			i += 1;
		}
		else if (line[i] == '<' && line[i + 1] == '<')
		{
			data->redir->count_heredoc++;
			data->redir->r_in = true;
			i += 1;
		}
		line++;
	}
}

char	*check_redir(char *line, t_data *data)
{
	int i;

	i = 0;
	while (line && line[i] && (data->redir->r_out == true || data->redir->r_in == true))
	{
		if (line[i] == '<' || line[i] == '>')
			manage_redir(line, i, data);
		i++;
	}
	if (data->redir->bad_r == true)
	{
		free(line);
		line = NULL;
		data->redir->bad_r = false;
	}
	return (line);
}
