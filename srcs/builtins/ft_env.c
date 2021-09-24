/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:38:59 by ldes-cou@         #+#    #+#             */
/*   Updated: 2021/09/24 14:43:00 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**run a program in a modified environment
**without arg, it only print all env variables 
*/
#include "../../includes/minishell.h"

int	ft_env(t_list *env)
{
	t_list *tmp;
	
	if (env == NULL)
	{
		perror("env");
		return (1);
	}
	tmp = env;
	while(env != NULL)
	{
		printf("%s\n", env->content);
		env = env->next;
	}
	env = tmp;
	return (0);
}
