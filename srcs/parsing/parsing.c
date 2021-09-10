/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:20:02 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/10 09:41:02 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void	parser(char *line, t_dlist *list)
{
	if (line)
	{
		printf("%s\n", line);
	}
	else 
		exit(0);
}