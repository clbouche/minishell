/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:11:54 by claclou           #+#    #+#             */
/*   Updated: 2021/09/21 10:59:01 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_token		g_get_tok_type[CHR_MAX] = {
	[CHR_ALPHA] = T_CMD,
	[CHR_DASH] = T_OPT,
	[CHR_QUOTE] = T_ARG,
	//[CHR_DIGIT] = T_WORD
};

static t_chr_class		g_get_chr_class[255] =
{
	['A'...'Z'] = CHR_ALPHA,
	['a'...'z'] = CHR_ALPHA,
	['-'] = CHR_DASH,
	['"'] = CHR_QUOTE,
	[' '] = CHR_SPACE,
	['$'] = CHR_DOL,
	['0'...'9'] = CHR_DIGIT,
	[';'] = CHR_SEMI,
};

static int				g_token_chr_rules[T_MAX][CHR_MAX] =
{
	[T_OPT] = {
		[CHR_DASH] = 1,
		[CHR_ALPHA] = 1
	},
	[T_ARG] = {
		[CHR_QUOTE] = 1,
	},
};

/*
** On contextualise d'abord le node par rapport à son first char 
** (ex : T_CMD)
** Puis, on cherche à vérifier si ce contexte est bon durant TOUT
** le node. Dès que le contexte change, selon les règles que l'on
** a précisé, le token change. 
** On va vérifié alors que ce nouveau contexte est valable jusqu'à 
** la fin du node. Lorsqu'on a terminé la lecture du node : 
** tokenisation terminé. 
*/

unsigned int	define_token(t_node *node)
{
	unsigned int i;
	unsigned int tok_type;

	i = 1;
	tok_type = g_get_tok_type[g_get_chr_class[node->value[0]]];
	printf("define token is 1: %u\n", tok_type);
	while (node->value[i])
	{
		tok_type = g_token_chr_rules[tok_type][g_get_chr_class[i]];
		i++;
		//tester plusieurs combinaisons pour voir si ça fonctionne
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
		printf("put token is : : %u\n\n", temp->type);
		temp = temp->next;
	}
	return (list);
}

//a la place de tokenizer les maillons
// -> creer les maillons en fonction de tokens ??