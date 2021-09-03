/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 15:26:52 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/30 12:21:46 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int argc, char **argv, char **env)
{
	char *line;

	if (argc == 1)
	{
		//initialisation
		while (1)
		{
			//faire le parsing de la ligne envoye
			ft_putstr_fd("minishell$  ", 0);
			get_next_line(0, &line);
		}
	}
	//fonctions de free
	return (0);
}