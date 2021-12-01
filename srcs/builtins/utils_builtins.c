/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:24:35 by clbouche          #+#    #+#             */
/*   Updated: 2021/12/01 13:46:32 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_var(char *var, t_data *d)
{
	t_list	*tmp;
	char	*name_var;

	tmp = d->env;
	while (tmp != NULL)
	{
		name_var = find_name(tmp->content);
		if (ft_strncmp(var, name_var, (ft_strlen(var))) == 0)
		{
			d->env = delete_node(d->env, var);
			d->ret = SUCCESS;
			ft_memdel(&name_var);
			return ;
		}
		ft_memdel(&name_var);
		tmp = tmp->next;
	}
	d->ret = FAILURE;
	return ;
}
