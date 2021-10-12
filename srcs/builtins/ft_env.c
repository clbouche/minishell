/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:38:59 by ldes-cou@         #+#    #+#             */
/*   Updated: 2021/10/12 15:01:58 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**run a program in a modified environment
**without arg, it only print all env variables 
*/
#include "minishell.h"

void	ft_env(t_data *d)
{
	t_list *tmp;
	
	if (d->env == NULL)
	{
		ft_putstr_fd("there is no environment", 2);
		d->ret = FAILURE;
	}
	tmp = d->env;
	while(d->env != NULL)
	{
		printf("%s\n", (char *)d->env->content);
		d->env = d->env->next;
	}
	d->env = tmp;
	d->ret = FAILURE;
}

char *find_var(char *name)
{
	char *var;

	var = NULL;
	var = ft_strchr(name, '=');
	return(var + 1);
}

char *find_name(char *var)
{
	char *name;
	int i;

	i = 0;
	while (var[i] != '=')
		i++;
	name = ft_substr(var, 0, i);
	return(name);
	
}