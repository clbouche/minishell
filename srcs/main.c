/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:36:27 by claclou           #+#    #+#             */
/*   Updated: 2021/09/20 16:18:18 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int argc, char **argv)
{
	int i = 1;
	int j = 0;
	t_dlist *list;
	
	list = ft_dlstnew(argv[1]);
	while (argv[i])
	{
		ft_dlstadd_back(list, argv[i]);
		i++;
	}
	print_dlist(list);
}