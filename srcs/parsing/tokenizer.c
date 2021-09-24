/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:11:54 by claclou           #+#    #+#             */
/*   Updated: 2021/09/24 08:58:13 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_token_type		get_tok_type[CHR_MAX] = {
	//[CHR_ALPHA] = T_CMD,
	//[CHR_DASH] = T_OPT,
	[CHR_QUOTE] = T_ARG,
	[CHR_ALPHA] = T_ARG,
	[CHR_DIGIT] = T_ARG,
	[CHR_SEP] = T_SEP,
	//[CHR_DIGIT] = T_WORD
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
	//['$'] = CHR_DOL,
	//[';'] = CHR_SEMI,
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
		[CHR_NL] = 0,
	}
};

t_token	save_token(char *s, int anchor, t_token_type toktype)
{
	t_token ret;
	
	ret.tok_type = toktype;
	ret.data = strndup(s, anchor);
	return ret;
}

/*t_token	get_token(char *input, int *i, t_token_type tok_type)
{
	t_chr_class	chr_class;
	int			anchor;

	anchor = 1;
	while (input[*i] && token_chr_rules[tok_type][(chr_class = get_chr_class[(unsigned char)input[*i]])])
	{
		anchor++;
		(*i)++;
	}
	return (save_token(input + (*i - anchor), anchor, tok_type));
}*/


void	ignore_wspace(char *s, int *i)
{
	while (s[*i] && get_chr_class[(unsigned char)s[*i]] == CHR_SEP)
		(*i)++;
}

t_token	split_token(char *input)
{
	t_chr_class		chr_class;
	t_token_type 	tok_type;
	t_token 		token;
	static int		i = 0;

	chr_class = 0;
	//skip les espaces du début
	//gerer plus tard si le char est un operateur
	//si on atteint la fin de la ligne
	if (input[i] == '\0')
		return (token);
		//save_token();
	//on va recup le char sur lequel on se trouve
	chr_class = get_chr_class[(unsigned char)input[i]];
	//si c'est un separateur, on ignore ces char + recursif
	if (chr_class == CHR_SEP)
	{
		printf("enter\n");
		ignore_wspace(input, &i);
		return (split_token(input));
	}
	//si rien de ça = mot a exploiter 
	tok_type = get_tok_type[chr_class];
	i++;
	//token = get_token(input, &i, tok_type);
	//recuperation des infos du futur node
	return (token);
}


void	tokenizer(char *line)
{
	/*if (!line)
		exit(0);
	split_line = ft_split(line, ' ');
	while (split_line[i] != NULL)
	{
		ft_dlstadd_back(list, split_line[i]);
		i++;
	}
	print_dlist(list);
	put_token(list);*/
}
