/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:46:38 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/13 17:44:07 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Verifie les caracteres qui n'ont pas le droit de constituer 
** le nom d'une variable
*/
int	check_unvalid_char(int i)
{
	if (i == '\\' || i == '$' || i == '"'
		|| i == '\'' || i == '>' || i == '<')
		return (FAILURE);
	return (SUCCESS);
}

int	len_name(char *name)
{
	int	len;

	len = 1;
	// && check_unvalid_char(name[len] == SUCCESS))
	while (name[len] != ' ' && name[len] != '=')
		len++;
	return (len);
}

/*char	*recup_content(char *var)
{
	int	i;

	i = 0;
	while(var[i])
	{

	}
}*/

/*
** Va remplacer la valeur $exemple par le contenu
** de la variable $exemple dans un char **.
*/
char	**create_new_input(char *line, char *name, t_data *data)
{
	(void)line;
	char 	**new_input;
	char	*name_var;
	char	*content;
	t_list	*tmp;

	new_input = NULL;
	tmp = data->env;
	while (tmp != NULL)
	{
		name_var = find_name(tmp->content);
		if (ft_strcmp(name, name_var) == 0)
		{
			content = find_var(tmp->content);
			printf("content : %s\n", content);
			printf("env : %s\n", (char *)tmp->content);
		}
		tmp = tmp->next;
	}
	// new input = la meme chose jusqu'a croiser $, 
	//si $ : remplacer par le contenu 
	//si $ suivi de rien, le contenu est "\n"
	//remettre la suite normalement
	return (new_input);
}

/*
** Recuperer le nom et le contenu de la variable.
** Et eliminer les caracteres interdit.
*/
void	manage_variable(char *line, t_data *data)
{
	char	*name;
	int		i;
	int		j;
	int		len_n;

	i = 1;
	j = 0;
	len_n = len_name(line);
	name = malloc(sizeof(char) * len_n);
	//+ (check_unvalid_char(line[i]) == FAILURE)
	while (line[i] != ' ' && line[i] != '=')
		name[j++] = line[i++];
	create_new_input(line, name, data);
}
