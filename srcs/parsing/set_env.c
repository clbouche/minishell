/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:09:16 by ldes-cou@         #+#    #+#             */
/*   Updated: 2021/10/01 10:35:44 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list *get_env(t_data *d, char **envp)
{
	t_list *new;
	char *var;
	int i;
	
	new = NULL;
	var = NULL;
	i = -1;
	while (envp[++i])
	{
		var = ft_strdup(envp[i]);
		if (var == NULL)
			free_exit(d->env, "malloc error");
		new = ft_lstnew(var);
		if (new == NULL)
			free_exit(d->env, "chained list error");
		ft_lstadd_back(&d->env, new);
		d->env_len++;	
	}
	printf("%i\n", d->env_len);
	return(d->env);
}
	
void free_lst(t_list *lst)
{
	t_list *tofree;

	tofree = NULL;
	while (lst != NULL)
	{
		tofree = lst;
		free(tofree);
		lst = lst->next;
	}
}

void free_exit(t_list *lst, char *error)
{
	perror("error");
	free_lst(lst);
	exit(FAILURE);
}
	
