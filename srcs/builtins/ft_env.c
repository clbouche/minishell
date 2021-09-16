/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:38:59 by ldes-cou@         #+#    #+#             */
/*   Updated: 2021/09/16 13:40:43 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**run a program in a modified environment
**without arg, it only print all env variables 
*/
#include "../../includes/minishell.h"

void	ft_env(t_list *env)
{
	t_list *tmp;
	
	tmp = env;
	while(env != NULL)
	{
		printf("%s\n", env->content);
		env = env->next;
	}
	env = tmp;
}
