/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:54:08 by claclou           #+#    #+#             */
/*   Updated: 2021/10/21 12:30:34 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_char(char c)
{
	if (c == '"' || c == '\'' || c == '<' || c == '>' || c == ' ')
		return (FALSE);
	return(SUCCESS);
}

/*
** Utile pour le malloc.
*/
int	recup_file_len(char *str)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while(str[i] == ' ')
		i++;
	while(str[i])
	{
		if (check_char(str[i]) == SUCCESS)
			j++;
		i++;
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
	int		len;
	char	*file_name;

	i = 0;
	j = 0;
	len = recup_file_len(str);
	file_name = malloc(sizeof(char) * (len + 1));
	while(str[i] == ' ')
		i++;
	while(str[i])
	{
		if (check_char(str[i]) == SUCCESS)
			file_name[j++] = str[i++];
		else
		{
			printf("check str[i] = %c\n", str[i]);
			if (str[i] == '>')
				{
					printf("file_name 1 : %s\n", file_name);
					return(file_name);
				}

		}
	}
	file_name[j] = '\0';
	printf("file_name 2: %s\n", file_name);
	return (file_name);
}

/*void	manage_quotes_redir(char *input, int *i, char quote)
{

}*/

/*
** Verifie le type de redirections dont il s'agit 
** pour envoyer a la bonne fonction.
*/
void	check_redir(char *input, int i, t_data *data)
{
	int		j;

	j = i;
	if (input[i] == '>' && input[i + 1] != '>')
		redir_ouput(&input[i + 1], data);
	else if (input[i] == '>' && input[i + 1] == '>')
		redir_output_append(&input[i + 2], data);
	else if (input[i] == '<' && input[i + 1] != '<')
		redir_input(input, data);
	else if (input[i] == '<' && input[i + 1] == '<')
		redir_read_input(&input[i + 2], data);
	input[i] = '\0';
}