/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:12:46 by clbouche          #+#    #+#             */
/*   Updated: 2021/12/02 17:57:05 by ldes-cou         ###   ########.fr       */
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

void	expand(char *input, char *new_input, t_data *data)
{
	new_input = manage_expand(input, check_expand(input), data);
	input = new_input;
}

void	bash_avertissement(char *del, char *input)
{
	ft_putstr_fd("bash: avertissement : « here-document » (wanted '", 2);
	ft_putstr_fd(del, 2);
	ft_putendl_fd("')", 2);
	free(input);
}

void	write_free_input(char *input, t_data *data)
{
	write(data->fds[1], input, ft_strlen(input));
	write(data->fds[1], "\n", 1);
	free(input);
}

void	heredoc_loop(char *delimiter, t_data *data)
{
	char	*input;
	char	*new_input;

	new_input = NULL;
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
			ft_memdel(&input);
			break ;
		}
		if (check_expand(input) >= 0)
			expand(input, new_input, data);
		write_free_input(input, data);
	}
}
