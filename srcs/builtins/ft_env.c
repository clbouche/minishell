/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:38:59 by ldes-cou@         #+#    #+#             */
/*   Updated: 2021/11/30 09:57:19 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**run a program in a modified environment
**without arg, it only print all env variables 
*/
#include "minishell.h"

void	ft_env(t_data *d, char **cmd)
{
	t_list	*tmp;

	if (cmd[1])
	{
		ft_putstr_fd("error env\n", 1);
		d->ret = FAILURE;
		free_array(cmd);
		return ;
	}
	if (d->env == NULL)
	{
		ft_putstr_fd("there is no environment", 2);
		d->ret = FAILURE;
	}
	tmp = d->env;
	while (d->env != NULL)
	{
		printf("%s\n", (char *)d->env->content);
		d->env = d->env->next;
	}
	d->env = tmp;
	d->ret = FAILURE;
	free_array(cmd);
}

char	*find_var(char *name)
{
	char	*var;

	var = NULL;
	var = ft_strchr(name, '=');
	if (!var)
		return (NULL);
	return (var + 1);
}

char	*find_name(char *var)
{
	char	*name;
	int		i;

	i = 0;
	while (var[i] != '=' && var[i])
		i++;
	name = ft_substr(var, 0, i);
	return (name);
}
