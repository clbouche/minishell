/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:12:46 by clbouche          #+#    #+#             */
/*   Updated: 2021/12/02 14:10:11 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_expand(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (i);
		i++;
	}
	return (-1);
}

void	bash_avertissement(char *del, char *input)
{
	ft_putstr_fd("bash: avertissement : « here-document » (wanted '", 2);
	ft_putstr_fd(del, 2);
	ft_putendl_fd("')", 2);
	free(input);
}

void	heredoc_loop(char *delimiter, t_data *data)
{
	char	*input;
	char	*new_input;
	int		i;

	while (true)
	{
		signal(SIGQUIT, &sig_quit);
		rl_outstream = stderr;
		input = readline("> ");
		if (!input)
		{
			bash_avertissement(delimiter, input);
			break ;
		}
		else if (ft_strcmp(input, delimiter) == 0)
		{
			free(input);
			input = NULL;
			break ;
		}
		i = check_expand(input);
		if (i >= 0)
		{
			new_input = manage_expand(input, i, data);
			input = new_input;
		}
		write(data->fds[1], input, ft_strlen(input));
		write(data->fds[1], "\n", 1);
		free(input);
	}
}
