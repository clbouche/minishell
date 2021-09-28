/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:38:59 by ldes-cou@         #+#    #+#             */
/*   Updated: 2021/09/28 10:16:37 by ldes-cou@st      ###   ########.fr       */
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
		ft_putstr_fd("there is no environment", 2);
		return (FAILURE);
	}
	tmp = env;
	while(env != NULL)
	{
		printf("%s\n", env->content);
		env = env->next;
	}
	env = tmp;
	return (SUCCESS);
}
