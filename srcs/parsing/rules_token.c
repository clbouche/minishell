/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:20:20 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/27 15:30:19 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token_type		get_tok_type[CHR_MAX] = {
	[CHR_QUOTE] = T_ARG_QUOTE,
	[CHR_ALPHA] = T_ARG,
	[CHR_DIGIT] = T_ARG,
	[CHR_SEP] = T_SEP,
	[CHR_DASH] = T_OPT,
	[CHR_PIPE] = T_PIPE,
	[CHR_REDIR_L] = T_REDIR,
	[CHR_REDIR_R] = T_REDIR,
};

t_chr_class		get_chr_class[255] =
{
	['A'...'Z'] = CHR_ALPHA,
	['a'...'z'] = CHR_ALPHA,
	['-'] = CHR_DASH,
	['"'] = CHR_QUOTE,
	[' '] = CHR_SEP,
	['\n'] = CHR_NL,
	['0'...'9'] = CHR_DIGIT,
	['|'] = CHR_PIPE,
	['>'] = CHR_REDIR_R,
	['<'] = CHR_REDIR_L,
	// ['$'] = CHR_DOL,
	// [';'] = CHR_SEMI,
};

int				token_chr_rules[T_MAX][CHR_MAX] =
{
	[T_SEP] = {
		[CHR_SEP] = 0,
	},
	[T_ARG] = {
		[CHR_DIGIT] = 1,
		[CHR_ALPHA] = 1,
		[CHR_NL] = 0,
		[CHR_SEP] = 0,
		[CHR_QUOTE] = 0,
	},
	[T_OPT] = {
		[CHR_DASH] = 1,
		[CHR_ALPHA] = 1,
		[CHR_SEP] = 0,
	},
	[T_PIPE] = {
		[CHR_PIPE] = 1,
		[CHR_SEP] = 0,
	},
	[T_ARG_QUOTE] = {
		[CHR_DIGIT] = 1,
		[CHR_ALPHA] = 1,
		[CHR_SEP] = 1,
		[CHR_PIPE] = 1,
		[CHR_REDIR_L] = 1,
		[CHR_REDIR_R] = 1,
		[CHR_NL] = 0,
		[CHR_QUOTE] = 0,
	}
};


t_token	get_token(char *input, int *i, t_token_type tok_type)
{
	t_chr_class	chr_class;
	int			len;

	len = 1;
	while (input[*i] && token_chr_rules[tok_type][(chr_class = get_chr_class[(unsigned char)input[*i]])])
	{
		len++;
		(*i)++;
	}
	return (save_token(input + (*i - len), len, tok_type));
}

/*t_token manage_quote(char *s, int *i, t_token_type tok_type)
{

}*/

t_token	split_token(char *input)
{
	t_chr_class		chr_class;
	t_token_type 	tok_type;
	t_token 		token;
	static int		i = 0;

	chr_class = 0;
	tok_type = 0;
	//gerer plus tard si le char est un operateur
	//gerer si on croise un char qu'on connait pas = erreur
	if (input[i] == '\0')
	{
		i = 0;
		return (save_token(NULL, 0, T_EOF));
	}
	chr_class = get_chr_class[(unsigned char)input[i]];
	if (chr_class == CHR_SEP)
	{
		ignore_wspace(input, &i);
		return (split_token(input));
	}
	tok_type = get_tok_type[chr_class];
	i++;
	token = get_token(input, &i, tok_type);
	return (token);
}