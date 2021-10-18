/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:46:38 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/15 13:24:03 by claclou          ###   ########.fr       */
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

	len = 0;
	// && check_unvalid_char(name[len] == SUCCESS))
	while (name[len] != ' ' && name[len] != '=')
		len++;
	return (len);
}

/*
** Cherche le contenu de la variable dans l'environnement
*/
char	*find_content(char *name, t_data *data)
{
	char	*name_var;
	char	*content;
	char	*tmp_content;
	t_list	*tmp;

	tmp = data->env;
	//content = malloc(sizeof(char) * ft_strlen(tmp->content));
	while (tmp != NULL)
	{
		name_var = find_name(tmp->content);
		if (ft_strcmp(name, name_var) == 0)
			tmp_content = find_var(tmp->content);
		tmp = tmp->next;
	}
	content = malloc(sizeof(char) * ft_strlen(tmp_content));
	content = tmp_content;
	return (content);
}

/* 
** Va concatener le debut de la ligne en remplacant 
** le nom de la variable par son contenu puis 
** garder la fin de la ligne tel quel.
*/
char	*create_new_input(char *line, char *content)
{
	int 	i;
	char	*new_input;

	i = 0;
	while (line[i] != '$')
		i++;
	new_input = malloc(sizeof(char) * (i + ft_strlen(content) + 1));
	ft_strlcat(new_input, line, i);
	ft_strcat(new_input, " ");
	ft_strcat(new_input, content);
	return (new_input);
}

/*
** Recuperer le nom et le contenu de la variable.
** Et eliminer les caracteres interdit.
*/
char	*manage_variable(char *line, t_data *data)
{
	char	*new_input;
	char	*name;
	char	*content;
	int		i;
	int		j;
	int		len_n;

	i = 0;
	j = 0;
	//printf("yolo\n");
	while(line[j] != '$')
		j++;
	len_n = len_name(&line[j + 1]);
	name = malloc(sizeof(char) * (len_n));
	//+ (check_unvalid_char(line[i]) == FAILURE)
	j++;
	while (line[j] != ' ' && line[j] != '=')
		name[i++] = line[j++];
	//name[i] = '\0';
	content = find_content(name, data);
	free(name);
	new_input = create_new_input(line, content);
	if (line[j] != ' ' || line[j] != '\0')
		ft_strcat(new_input, &line[j]);
	return(new_input);
}
