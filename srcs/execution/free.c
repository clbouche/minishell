/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:08:22 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/11/12 10:14:22 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			ft_memdel(&array[i]);
			i++;
		}
		free(array);
		array = NULL;
	}
}

void free_lst(t_list *lst)
{
	t_list	*tofree;

	tofree = NULL;
	if (lst == NULL)
		return;
	while (lst)
	{
		//printf("%s\n", (char *)lst->content);
		if (lst->content != NULL)
		{
			free(lst->content);
			lst->content = NULL;
		}
		tofree = lst;
		lst = lst->next;
		free(tofree);
		tofree = NULL;
	}
	return;
}

void	free_exit(t_data *d, char *error, int exit_code, char *pb)
{
	//perror(error);
	//ft_putstr_fd("🍄 MINISHELL 🍄 : ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(pb, 2);
	free_lst(d->env);
	free_array(d->envp);
	(void)exit_code;
	
	//exit(exit_code);
}

void	free_all(t_data *d)
{
	if (d->env != NULL)
		free_lst(d->env);
	//if (d->envp != NULL)
	//	free_array(d->envp);
}
