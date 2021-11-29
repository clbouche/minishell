/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:24:35 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/23 15:39:59 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_var(char *var, t_data *d)
{
	t_list	*tmp;
	char	*name_var;

	printf("var : %s\n", var);
	tmp = d->env;
	while (tmp != NULL)
	{
		name_var = find_name(tmp->content);
		if (ft_strncmp(var, name_var, (ft_strlen(var))) == 0)
		{
			d->env = delete_node(d->env, var);
			d->ret = SUCCESS;
			free(name_var);
			return ;
		}
		tmp = tmp->next;
	}
	d->ret = FAILURE;
	free(name_var);
	return ;
}
