/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:08:22 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/10/18 12:49:09 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}

void free_lst(t_list *lst)
{
	t_list	*tofree;

	tofree = NULL;
	if (lst)
	{
		while (lst->next!= NULL)
		{
			tofree = lst;
			printf("%s\n", (char *)tofree->content);
			if (tofree->content != NULL)
			{
				free(tofree->content);
				tofree->content = NULL;
			}
			lst = lst->next;
			free(tofree);
			tofree = NULL;
		}
		free(lst);
		lst = NULL;
	}
}

void	free_exit(t_list *lst, char *error)
{
	perror(error);
	free_lst(lst);
	exit(FAILURE);
}
