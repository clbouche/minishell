/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:11:54 by claclou           #+#    #+#             */
/*   Updated: 2021/09/24 14:31:25 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"



t_token	save_token(char *s, int len, t_token_type toktype)
{
	t_token rtn;
	
	rtn.tok_type = toktype;
	rtn.data = strndup(s, len);
	// printf("check ret tok: %u\n", rtn.tok_type);
	// printf("check ret data : %s\n", rtn.data);
	return rtn;
}

t_token	get_token(char *input, int *i, t_token_type tok_type)
{
	t_chr_class	chr_class;
	int			len;

	len = 1;
	//il faut definir correctement les regles des tokens pour recuperer les bonnes infos
	while (input[*i] && token_chr_rules[tok_type][(chr_class = get_chr_class[(unsigned char)input[*i]])])
	{
		len++;
		(*i)++;
	}
	return (save_token(input + (*i - len), len, tok_type));
}


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
	tok_type = 0;
	//gerer plus tard si le char est un operateur
	//gerer si on croise un char qu'on connait pas = erreur
	//si on atteint la fin de la ligne
	if (input[i] == '\0')
	{
		//clean les statiques
		return (save_token(NULL, 0, T_EOF));
	}
	//on va recup le char sur lequel on se trouve
	chr_class = get_chr_class[(unsigned char)input[i]];
	// printf("check char class : %u\n", chr_class);
	//si c'est un separateur, on ignore ces char + recursif
	if (chr_class == CHR_SEP)
	{
		// printf("check char sep : %u\n", chr_class);
		ignore_wspace(input, &i);
		return (split_token(input));
	}
	//si rien de ça = mot a exploiter 
	tok_type = get_tok_type[chr_class];
	// printf("check token : %u\n", tok_type);
	i++;
	token = get_token(input, &i, tok_type);
	//recuperation des infos du futur node
	return (token);
}

