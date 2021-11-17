/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:12:46 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/17 15:37:06 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Permet de determiner si le delimiteur a ete croise ou non.
** Le delimiteur doit constituer l'integralite de la ligne. 
** Il ne doit pas juste "faire partie" de la ligne.
*/

int		len_delimiter(char *str)
{
	int i;
	int	len;
	char	quote;

	i = 0;
	len = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] && (str[i] == '"' || str[i] == '\''))
	{
		quote = str[i++];
		while(str[i + len] != quote)
			len++;
		i++;
	}
	else
	{
		//i++;
		while(str[i + len] && (str[i] != ' ' || str[i] != '\0'))
			len++;
	}
	return (len);
}

char	*define_delimiter(char *str)
{
	int 	i;
	int		j;
	char	quote;
	char *delimiter;

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
		while(str[i] && str[i] != quote)
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
	//delimiter[j] = '\0';
	return (delimiter);
	//comment gerer les doubles quotes en pleins milieux
	// = interpreter comme non existante
	//accolades consideres comme char normal
	//idem pour expand = ne pas exploiter la variable. 
}

int		check_expand(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '$')
			return (i);
		i++;
	}
	return (-1);
}

void	heredoc_loop(char *delimiter, t_data *data, int *heredocs)
{

	char	*input;
	char *new_input;
	int		i;

	(void)heredocs;
	while(true)
	{
		//rl_catch_signals = 0;
		input = readline("> ");
		if (!input)
		{
			ft_putstr_fd("bash: avertissement : « here-document »\n", 2);
			break ;
		}
		if (ft_strcmp(input, delimiter) == 0) //|| g_sig.sigint == 1 || input == NULL)
		{
			// if (input == NULL)
			// 	heredoc_quit(delimiter);
			free(input);
			input = NULL;
			break;
		}
		i = check_expand(input);
		if (i >= 0)
		{
			new_input = manage_expand(input, data);
			input = new_input;
		}
		free(input);
	}
}