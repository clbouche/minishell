/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:12:46 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/29 15:26:31 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Permet de determiner si le delimiteur a ete croise ou non.
** Le delimiteur doit constituer l'integralite de la ligne. 
** Il ne doit pas juste "faire partie" de la ligne.
*/

int	len_delimiter(char *str)
{
	int		i;
	int		len;
	char	quote;

	i = 0;
	len = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] && (str[i] == '"' || str[i] == '\''))
	{
		quote = str[i++];
		while (str[i + len] != quote)
			len++;
		i++;
	}
	else
	{
		while(str[i + len] && (str[i] != ' ' || str[i] != '\0'))
			len++;
	}
	return (len);
}

char	*define_delimiter(char *str)
{
	int		i;
	int		j;
	char	quote;
	char	*delimiter;

	i = 0;
	j = 0;
	delimiter = malloc(sizeof(char) * (len_delimiter(str) + 1));
	if (!delimiter)
		exit(EXIT_FAILURE);
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '"' || str[i] == '\'')
	{
		quote = str[i];
		str[i++] = ' ';
		while (str[i] && str[i] != quote)
		{
			delimiter[j++] = str[i];
			str[i++] = ' ';
		}
	}
	else
	{
		while (str[i] && str[i] != ' ')
		{
			delimiter[j++] = str[i];
			str[i++] = ' ';
		}
	}
	delimiter[j] = '\0';
	return (delimiter);
	//comment gerer les doubles quotes en pleins milieux
	// = interpreter comme non existante
	//accolades consideres comme char normal
	//idem pour expand = ne pas exploiter la variable. 
}

int		check_expand(char *str)
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

	while(true)
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
			//free(input);
			//input = NULL;
			break ;
		}
		i = check_expand(input);
		if (i >= 0)
		{
			new_input = manage_expand(input, i, data);
			input = new_input;
		}
		// write(data->fds[1] , input, ft_strlen(input));
		// write(data->fds[1] , "\n", 1);
		pipe_out(data);
	}
}
