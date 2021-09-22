/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:11:54 by claclou           #+#    #+#             */
/*   Updated: 2021/09/22 12:53:25 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_token		g_get_tok_type[CHR_MAX] = {
	//[CHR_ALPHA] = T_CMD,
	[CHR_DASH] = T_OPT,
	[CHR_QUOTE] = T_ARG,
	[CHR_ALPHA] = T_ARG,
	[CHR_DIGIT] = T_ARG,
	[CHR_SEP] = T_SEP,
	//[CHR_DIGIT] = T_WORD
};

static t_chr_class		g_get_chr_class[255] =
{
	['A'...'Z'] = CHR_ALPHA,
	['a'...'z'] = CHR_ALPHA,
	['-'] = CHR_DASH,
	['"'] = CHR_QUOTE,
	[' '] = CHR_SEP,
	['\n'] = CHR_NL,
	['0'...'9'] = CHR_DIGIT,
	//['$'] = CHR_DOL,
	//[';'] = CHR_SEMI,
};

static int				g_token_chr_rules[T_MAX][CHR_MAX] =
{
	[T_SEP] = {
		[CHR_SEP] = 0,
	},
	[T_ARG] = {
		[CHR_QUOTE] = 1,
		[CHR_DASH] = 1,
		[CHR_DIGIT] = 1,
		[CHR_NL] = 0,
	}
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

unsigned int	define_token(char *input)
{
	int i;
	unsigned int tok_type;

	i = 1;
	tok_type = g_get_tok_type[g_get_chr_class[input[0]]];
	printf("define token is 1: %u\n", tok_type);
	while (input[i])
	{
		while (g_token_chr_rules[tok_type][g_get_chr_class[input[i]]])
			i++;
		//str = ft_substr(i, i); //ajouter 1 compteur 
		//ft_dlstadd_back(list, str);
		i += 1; // pas + 1, + le nombres de whitespace
	}
	printf("len : %i\n",  i);
	printf("tok type is 2 : %u\n", tok_type);
	return (tok_type);
}
