/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:11:54 by claclou           #+#    #+#             */
/*   Updated: 2021/09/28 15:32:22 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


t_token	save_token(char *s, int len, t_token_type toktype)
{
	t_token rtn;
	
	rtn.tok_type = toktype;
	rtn.data = strndup(s, len);
	return rtn;
}

void	ignore_wspace(char *s, int *i)
{
	while (s[*i] && get_chr_class[(unsigned char)s[*i]] == CHR_SEP)
		(*i)++;
}



