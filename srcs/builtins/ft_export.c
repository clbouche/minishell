/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:37:04 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/28 14:07:26 by clbouche         ###   ########.fr       */
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
	while (cmd[1][i])
	{
		if (cmd[1][i] == '=')
		{
			new_var = ft_lstnew(cmd[1]);
			ft_lstadd_back(&d->env, new_var);
			d->ret = SUCCESS;
			return ;
		}
		i++;
	}
	d->ret = UNKNOWN_COMMAND;
	return ;
}

//=>export_var
///don't forget to free
//==> don't forget to sort alphabetically the variables
int	ft_export(char **cmd, t_data *d)
{
	t_list	*tmp;
	char	**unset;
	char	*name;

	unset = NULL;
	if (cmd[1] != NULL)
	{
		name = find_name(cmd[1]);
		if (check_exist_var(name, d))
			export_var(cmd, d);
		//else
		//{
		//	export_var(cmd, d);
		//}
		return (SUCCESS);
	}
	tmp = d->env;
	while (d->env != NULL) //print alphabetically
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
	free_array(cmd);
	return (d->ret);
}
