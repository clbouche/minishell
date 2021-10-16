/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucrece <lucrece@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:09:16 by ldes-cou@         #+#    #+#             */
/*   Updated: 2021/10/16 09:47:52 by lucrece          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*get_env(t_data *d, char **envp)
{
	t_list	*new;
	char	*var;
	int		i;

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
	//printf("%i\n", d->env_len);
	return(d->env);
}

// t_list *set_lvl(t_list *env, char *lvl)
// {
// 	t_list *tmp;
// 	char *shlvl;

// 	tmp = env;
// 	while(tmp->next != NULL)
// 	{
// 		if (ft_strncmp("SHLVL", tmp->content, 5))
// 		{
// 			//
// 			// free(tmp->content);
// 			// shlvl = malloc(sizeof(char) * ft_intlen(lvl) + 7);
// 			// if (shlvl == NULL)
// 			// 	return (NULL);
// 			// shlvl = ft_strcpy("SHLVL=", shlvl);
// 			// shlvl = ft_strcat(shlvl, (char*)lvl);
// 			// tmp->content = ft_strdup(shlvl);
// 			// free(shlvl);
// 		}
// 	}
// 	return(env);
// }
void free_lst(t_list *lst)
{
	t_list	*tofree;

	tofree = NULL;
	while (lst != NULL)
	{
		tofree = lst;
		if (tofree->content != NULL)
			free(tofree->content);
		free(tofree);
		lst = lst->next;
	}
}

void	free_exit(t_list *lst, char *error)
{
	perror(error);
	free_lst(lst);
	exit(FAILURE);
}
