/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:02 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/28 15:35:37 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char **create_tab(t_token *tok, int nb_of_args, t_data *data)
{
	char **cmd;
	int	i;
	int len;
	int count;

	printf("token is data : %s\n", tok->data);
	printf("token is type : %u\n", tok->tok_type);
	//if (tok->tok_type != T_PIPE)
	//{
		cmd = malloc(sizeof(char **) * len);
		cmd[count] = ft_strdup(tok->data);
		printf("str : %s\n", cmd[count]);
		count++;
	//}
	//else
		// {
		// 	exit(0);
		// 	//gerer les pipes ici
		// }
	return (cmd);
}

void	parser(char *line, t_data *data)
{
	t_token tok;
	int		nb_of_args;
	char **cmd;

	while(tok.tok_type != T_EOF)	
	{
		//if (tok.tok_type == T_PIPE)
			// parser(line, data); -> envoyer a partir d'apres le pipe
		tok = split_token(line);
		nb_of_args++;
		cmd = create_tab(&tok, nb_of_args, data);
		line++;
	}
}
