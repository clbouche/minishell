/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:02 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/24 08:54:19 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


//#SUPPRIMER PRINT LIST#

void	print_dlist(t_dlist *lst)
{
	t_node	*temp;

	temp = lst->begin;
	if (lst == NULL)
		ft_error(ERR_EMPTY_DLIST);
	while (temp != NULL)
	{
		printf("[%s]\n", temp->value);
		temp = temp->next;
	}
}

t_dlist	*init_list(t_dlist *list)
{
	list = malloc(sizeof(t_dlist));
	if (!list)
		exit(0);
	list->end = NULL;
	list->begin = NULL;
	list->len = 0;
	return (list);
}


/*t_node	*save_node(t_node *left, t_tokens tok, t_node *right)
{
	t_node	*node = NULL;
	static int	cur_key = 0;

	if (!(node = malloc(sizeof(t_node))))
		exit(1);
	node->left = left;
	node->right = right;
	node->key = cur_key;
	node->tok = tok.tok;
	node->data = tok.data;
	cur_key++;
	return (node);
}

t_node	*put_in_node(char *input, t_token token)
{
	t_node	*node;

	if (!(node = malloc(sizeof(t_node))))
		exit(0);
	node->next = ;
	node->prev = ;
	node->token = ;
	node->value = ;
	node->index = ;
	return (node);
}*/

void	parser(char *line)
{
	t_token tok;
	t_node	*node;

	//ne pas faire de tokenisation pour les commandes simples
	tok = split_token(line);
	//node = put_in_node(input, &tok);

}

