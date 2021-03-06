/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:46:38 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/29 14:04:18 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** - Verifie si les chars sont valides
** - Fais une copie du nom de l'expand  
*/
char	*copy_name(char *line)
{
	int		i;
	int		len;
	int		j;
	char	*name;

	i = 0;
	len = 0;
	j = 0;
	name = NULL;
	while (line[i] && check_char(line[i]) && !spe_case(line[i]))
	{
		i++;
		len++;
	}
	if (len >= 1)
	{
		name = malloc(sizeof(char) * (len + 1));
		if (!name)
			return (0);
		i = 0;
		while (i < len)
			name[i++] = line[j++];
		name[i] = '\0';
	}
	return (name);
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
	tmp_content = NULL;
	while (tmp != NULL && tmp_content == NULL)
	{
		name_var = find_name(tmp->content);
		if (ft_strcmp(name, name_var) == 0)
			tmp_content = find_var(tmp->content);
		free(name_var);
		tmp = tmp->next;
	}
	if (tmp_content)
		content = ft_strdup(tmp_content);
	else
		content = ft_strdup(" ");
	return (content);
}

char	*add_end_line(char *input, char *line)
{
	int		i;
	char	*new_input;

	i = 0;
	new_input = NULL;
	while (line[i] && line[i] != '=')
		i++;
	if (line[i] == '=')
		new_input = ft_strjoin_realloc(&input, &line[i]);
	return (new_input);
}

/* 
** Va concatener le debut de la ligne en remplacant 
** le nom de la variable par son contenu puis 
** garder la fin de la ligne tel quel.
*/
char	*create_new_input(char *line, int i, char *content, int type)
{
	char	*new_input;
	char	*tmp;

	new_input = NULL;
	tmp = ft_substr(line, 0, i);
	new_input = ft_strjoin(tmp, content);
	free(tmp);
	i++;
	if (type == 0)
		i++;
	else if (type == 1)
	{
		while (line[i] && check_char(line[i]) && !spe_case(line[i]))
			i++;
	}
	if (line[i])
		new_input = ft_strjoin_realloc(&new_input, &line[i]);
	free(line);
	return (new_input);
}

/*
** Recuperer le nom et le contenu de la variable.
** Et eliminer les caracteres interdit.
*/
char	*manage_variable(char *line, int i, t_data *data)
{
	char	*new_input;
	char	*name;
	char	*content;
	int		type;

	new_input = NULL;
	name = NULL;
	content = NULL;
	type = -1;
	if (line[i + 1] == '?')
	{
		type = 0;
		content = ft_itoa(g_sig.status);
	}
	else if (check_char_begin(line[i + 1]))
	{
		type = 1;
		name = copy_name(&line[i + 1]);
		content = find_content(name, data);
	}
	if (line[i])
		new_input = create_new_input(line, i, content, type);
	free(name);
	free(content);
	return (new_input);
}
