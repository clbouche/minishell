/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:37:04 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/16 14:45:55 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** export a new variable takes 2 arg, the name of the new_var and the var
** without arg, it list env variables, in alphabetical order
*/

void	ft_export_var(t_list *env, char *name, char *variable)
{
	t_list *new_var;
	
	name = ft_strjoin(name, "=");
	new_var = ft_lstnew(ft_strjoin(name, variable));
	ft_lstadd_back(&env, new_var);
}
///don't forget to free
//==> don't forget to sort alphabetically the variables
void ft_export(t_list *env)
{
	t_list *tmp;

	tmp = env;
	while(env != NULL)
	{
		if (env->next == NULL)
		{
			printf(GREEN"declare -x ");
			printf("\"%s\"\n"RESET, env->content);
		}
		else
		{
			printf("declare -x ");
			printf("\"%s\"\n", env->content);
		}
		env = env->next;
	}
	env = tmp;
	
}
