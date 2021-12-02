/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:54:08 by claclou           #+#    #+#             */
/*   Updated: 2021/12/02 22:34:42 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	count_other_redir(char *line, t_data *data)
{
	int	i;

	i = 0;
	if (line[i] == '>' && line[i + 1] != '>')
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
}

void	count_redir(char *line, t_data *data)
{
	int	i;
	int	quote;

	i = 0;
	while (line[i])
	{
		if (line[i] == '"' || line[i] == '\'')
		{
			quote = line[i++];
			while (line[i] != quote)
				i++;
		}
		if (line[i] == '<' && line[i + 1] != '<')
		{
			data->redir->count_in++;
			data->redir->r_in = true;
		}
		count_other_redir(&line[i], data);
		line++;
	}
}

char	*check_redir(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (line && line[i] && (data->redir->r_out == true
			|| data->redir->r_in == true))
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
