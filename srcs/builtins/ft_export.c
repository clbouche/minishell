/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:37:04 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/07 11:37:26 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** export a new variable takes 2 arg, the name of the new_var and the var
** without arg, it list env variables, in alphabetical order
*/

void	export_var(char **cmd, t_data *d)
{
	t_list	*new_var;
	int		i;

	i = 0;
	printf("%s\n", cmd[1]);
	while(cmd[1][i])
	{
		if (cmd[1][i] == '=')
		{
			new_var = ft_lstnew(cmd[1]);
			ft_lstadd_back(&d->env, new_var);
			d->ret = SUCCESS;
			return;
		}
		i++;
	}
	d->ret = UNKNOWN_COMMAND;
	return;
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
		return(SUCCESS);
	}
	tmp = d->env;
	while(d->env != NULL) //print alphabetically
	{
		if (d->env->next == NULL)
		{
			printf("declare -x ");
			printf("\"%s\"\n", (char *)d->env->content);
		}
		else
		{
			printf("declare -x ");
			printf("\"%s\"\n", (char *)d->env->content);
		}
		d->env = d->env->next;
	}
	d->env = tmp;
	d->ret = SUCCESS;
	return (SUCCESS);
}
