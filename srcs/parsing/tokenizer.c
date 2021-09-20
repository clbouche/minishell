/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:11:54 by claclou           #+#    #+#             */
/*   Updated: 2021/09/20 11:28:43 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_token		g_get_tok_type[CHR_MAX] = {
	[CHR_ALPHA] = T_WORD,
	[CHR_DASH] = T_OPT,
	[CHR_DIGIT] = T_WORD,
};

static t_chr_class		g_get_chr_class[255] =
{
	['A'...'Z'] = CHR_ALPHA,
	['a'...'z'] = CHR_ALPHA,
	['-'] = CHR_DASH,
	['"'] = CHR_QUOTE,
	//[' '] = CHR_SPACE,
	//['$'] = CHR_DOL,
	//['0'...'9'] = CHR_DIGIT,
	//[';'] = CHR_SEMI,
};

static int				g_token_chr_rules[T_MAX][CHR_MAX] =
{
	[T_CMD] = {
		[CHR_ALPHA] = 1,
	},
	[T_OPT] = {
		[CHR_DASH] = 1,
		[CHR_ALPHA] = 1,
		[CHR_DIGIT] = 1,
		[CHR_QUOTE] = 0,
	},
	[T_ARG] = {
		[CHR_ALPHA] = 1,
		[CHR_QUOTE] = 1,
	},
};

unsigned int	define_token(t_node *node)
{
	unsigned int i;
	unsigned int tok_type;

	i = 1;
	tok_type = g_get_tok_type[g_get_chr_class[node->value[0]]];
	while (node->value[i])
	{
		node->type = g_token_chr_rules[tok_type][g_get_chr_class[i]];
		i++;
		//tester plusieurs combinaisons pour voir si ça fonctionne
		//definir plus de règles dans le .h
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
		temp = temp->next;
	}
	return (list);
}