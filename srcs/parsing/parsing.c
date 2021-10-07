/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:02 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/07 11:37:26 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


//#SUPPRIMER PRINT LIST#

// void	print_list(t_dlist *lst)
// {
// 	t_node	*temp;

// 	temp = lst->begin;
// 	if (lst == NULL)
// 		ft_error(ERR_EMPTY_DLIST);
// 	while (temp != NULL)
// 	{
// 		printf("value : [%s]\n", temp->value);
// 		printf("index : [%i]\n", temp->index);
// 		printf("token : [%u]\n", temp->token);
// 		temp = temp->next;
// 	}
// }

// t_dlist	*init_list(t_dlist *list)
// {
// 	list = malloc(sizeof(t_dlist));
// 	if (!list)
// 		exit(0);
// 	list->end = NULL;
// 	list->begin = NULL;
// 	list->len = 0;
// 	return (list);
// }

// t_dlist	*ft_add_node(t_dlist *lst, t_token *node, int index)
// {
// 	t_node	*new_node;

// 	new_node = (t_node *)malloc(sizeof(t_node));
// 	if (new_node == NULL || lst == NULL)
// 		ft_error(ERR_ALLOC);
// 	new_node->value = node->data;
// 	new_node->token = node->tok_type;
// 	new_node->next = NULL;
// 	new_node->prev = NULL;
// 	new_node->index = index;
// 	if (lst->len == 0)
// 	{
// 		lst->begin = new_node;
// 		lst->end = new_node;
// 	}
// 	else
// 	{
// 		lst->end->next = new_node;
// 		new_node->prev = lst->end;
// 		lst->end = new_node;
// 	}
// 	lst->len += 1;
// 	return (lst);
// }

// t_dlist	*put_in_node(t_dlist *lst, t_token *node, int index)
// {
// 	ft_add_node(lst, node, index);
// 	return (lst);
// }

// void	parser(char *line)
// {
// 	int len;
// 	t_token tok;
// 	t_dlist *lst;
// 	t_node	*node;
// 	static int index = 0;

// 	len = ft_strlen(line);
// 	lst = init_list(lst);
// 	//ne pas faire de tokenisation pour les commandes simples
// 	while(tok.tok_type != T_EOF)	
// 	{
// 		tok = split_token(line);
// 		index++;
// 		lst = put_in_node(lst, &tok, index);
// 		line++;
// 	}
// 	print_list(lst);
// 	//besoin de clean les statics sinon lors du relancement du prompt ca reset pas lol 
// }
