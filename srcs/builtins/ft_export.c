/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:37:04 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/27 14:27:36 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** export a new variable takes 2 arg, the name of the new_var and the var
** without arg, it list env variables, in alphabetical order
*/

void	export_var(char **cmd, t_data *d)
{
	t_list	*new_var;

	new_var = ft_lstnew(cmd[1]);
	ft_lstadd_back(&d->env, new_var);
	d->ret = 0;
}

//=>export_var
///don't forget to free
//==> don't forget to sort alphabetically the variables
int		ft_export(char **cmd, t_data *d)
{
	t_list *tmp;
	
	if(cmd[1] != NULL)
	{
		export_var(cmd, d);
		return(0);
	}
	tmp = d->env;
	while(d->env != NULL) //print alphabetically
	{
		if (d->env->next == NULL)
		{
			printf("declare -x ");
			printf("\"%s\"\n", d->env->content);
		}
		else
		{
			printf("declare -x ");
			printf("\"%s\"\n", d->env->content);
		}
		d->env = d->env->next;
	}
	d->env = tmp;
	d->ret = 0;
}
