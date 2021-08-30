/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/25 17:28:29 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int argc, char **argv)
{
	char *line;

	if (argc == 1)
	{
		while (42)
		{
			ft_putstr_fd("minishell$", 0);
			get_next_line(0, &line);
		}
		//initialisation
		//lancement du prompt
		//lecture du prompt
	}
	//fonctions de free
	return (0);
}