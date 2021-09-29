/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:38:59 by ldes-cou@         #+#    #+#             */
/*   Updated: 2021/09/29 15:57:59 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**run a program in a modified environment
**without arg, it only print all env variables 
*/
#include "../../includes/minishell.h"

void	ft_env(t_list *env, t_data *d)
{
	t_list *tmp;
	
	if (env == NULL)
	{
		ft_putstr_fd("there is no environment", 2);
		d->ret = FAILURE;
	}
	tmp = env;
	while(env != NULL)
	{
		printf("%s\n", (char *)env->content);
		env = env->next;
	}
	env = tmp;
	d->ret = FAILURE;
}
