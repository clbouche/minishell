/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:02 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/16 12:54:55 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

unsigned int	define_token(t_node *node)
{
	int i;
	unsigned int tok_type;

	i = 0;
	while (node->value[i])
	{
		tok_type = g_get_tok_type[g_get_chr_class[node->value[i]]];
		i++;
	}
	printf("define token is : %u\n", tok_type);
	return (tok_type);
}

t_dlist	*put_token(t_dlist *list)
{
	t_node		*temp;

	temp = list->begin;
	while (temp != NULL)
	{
		temp->type = define_token(temp);
		printf("put token is : %u\n", temp->type);
		temp = temp->next;
	}
	return (list);
}

void	parser(char *line)
{
	int i;
	t_dlist *list;
	char **split_line;

	i = 0;
	list = init_list(list);
	if (!line)
		exit(0);
	split_line = ft_split(line, ' ');
	while (split_line[i] != NULL)
	{
		ft_add_node(list, split_line[i]);
		i++;
	}
	print_dlist(list);
	put_token(list);
}