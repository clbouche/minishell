/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:02 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/08 16:01:18 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parser(char *line, t_list *list)
{
	t_list	*new;

	if (line)
	{
		printf("%s\n", line);
		//list = ft_lstnew(&line);
		//ft_lstadd_front(&list, new);
		//list = ft_lstnew("bojour a tous");
		
		//ft_lstadd_back(&list, );
		//ft_lstprint(list);
	}
	else 
		exit(0);
}