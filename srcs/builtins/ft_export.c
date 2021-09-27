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

t_list	*export_var(char **cmd)
{
	t_list	*new_var;
	t_list	*env;
	//char *name;
	
	//name = ft_strjoin(cmd[1], "=");//dont forget to free
	new_var = ft_lstnew(cmd[1]);
	ft_lstadd_back(&env, new_var);
	return(env);
}

//=>export_var
///don't forget to free
//==> don't forget to sort alphabetically the variables
int ft_export(char **cmd)
{
	t_list *tmp;
	t_list *env;
	
	if(cmd[1] != NULL)
	{
		export_var(cmd);
		return(0);
	}
	tmp = env;
	while(env != NULL) //print alphabetically
	{
		if (env->next == NULL)
		{
			printf("declare -x ");
			printf("\"%s\"\n", env->content);
		}
		else
		{
			printf("declare -x ");
			printf("\"%s\"\n", env->content);
		}
		env = env->next;
	}
	env = tmp;
	return(0);
}
