/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:46:38 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/25 15:21:14 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	len_name(char *name)
{
	int	len;

	len = 0;
	// && check_unvalid_char(name[len] == SUCCESS))
	while (name[len] && name[len] != ' ' && name[len] != '=' && name[len] != '"' && name[len] != '$' && name[len] != '}')
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

char	*add_end_line(char *input, char *line)
{
	int i;
	char	*new_input;

	i = 0;
	new_input = NULL;
	while(line[i] && line[i] != '=')
		i++;
	if (line[i] == '=')
		new_input = ft_strjoin_realloc(&input, &line[i]);
	return(new_input);
}

/* 
** Va concatener le debut de la ligne en remplacant 
** le nom de la variable par son contenu puis 
** garder la fin de la ligne tel quel.
*/
char	*create_new_input(char *line, char *content)
{
	int 	i;
	int		j;
	char	*new_input;
	char	*tmp;
	
	i = 0;
	j = 0;
	new_input = NULL;
	while (line[i] && line[i] != '$')
		i++;
	tmp = ft_substr(line, 0, i);
	new_input = ft_strjoin(tmp, content);
	//printf("new input : %s\n", new_input);
	//printf("line : %s\n", &line[i]);
	free(tmp);
	while(line[i] && line[i] != ' ' && line[i] != '=' && line[i] != '"') //&& line[i] != '$' && line[i] != '}')
		i++;
	if(line[i])
		new_input = ft_strjoin_realloc(&new_input, &line[i]);
	//printf("new input 2 : %s\n", new_input);
	//exit(1);
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
	new_input = NULL;
	while(line[j] != '$')
		j++;
	len_n = len_name(&line[j + 1]);
	name = ft_substr(line, (j + 1), len_n);
	content = find_content(name, data);
	free(name);
	new_input = create_new_input(line, content);
	return(new_input);
}
