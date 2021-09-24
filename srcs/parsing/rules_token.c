/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 14:20:20 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/24 14:31:16 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_token_type		get_tok_type[CHR_MAX] = {
	[CHR_QUOTE] = T_ARG,
	[CHR_ALPHA] = T_ARG,
	[CHR_DIGIT] = T_ARG,
	[CHR_SEP] = T_SEP,
	[CHR_DASH] = T_OPT,
	[CHR_PIPE] = T_PIPE,
	[CHR_REDIR_L] = T_REDIR,
	[CHR_REDIR_R] = T_REDIR,
};

static t_chr_class		get_chr_class[255] =
{
	['A'...'Z'] = CHR_ALPHA,
	['a'...'z'] = CHR_ALPHA,
	['-'] = CHR_DASH,
	['"'] = CHR_QUOTE,
	[' '] = CHR_SEP,
	['\n'] = CHR_NL,
	['0'...'9'] = CHR_DIGIT,
	['|'] = CHR_PIPE,
	['$'] = CHR_DOL,
	[';'] = CHR_SEMI,
	['>'] = CHR_REDIR_R,
	['<'] = CHR_REDIR_L,
};

static int				token_chr_rules[T_MAX][CHR_MAX] =
{
	[T_SEP] = {
		[CHR_SEP] = 0,
	},
	[T_ARG] = {
		[CHR_QUOTE] = 1,
		[CHR_DASH] = 1,
		[CHR_DIGIT] = 1,
		[CHR_ALPHA] = 1,
		[CHR_NL] = 0,
		[CHR_SEP] = 0,
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
};
