/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:08:22 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/12/02 11:46:38 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array && array[i])
		{
			//printf("array[i] == %s\n", array[i]);
			free(array[i]);
			array[i] = NULL;
 			i++;
		}
		free(array);
		array = NULL;
	}
}

void	free_lst(t_list *lst)
{
	t_list	*tofree;

	tofree = NULL;
	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		if (lst->content != NULL)
		{
			//printf("%s\n", (char *)lst->content);
			free(lst->content);
			lst->content = NULL;
		}
		tofree = lst;
		lst = lst->next;
		free(tofree);
		tofree = NULL;
	}
	return ;
}

void	free_exit(t_data *d, char *error, int exit_code, char *pb)
{
	ft_putstr_fd(error, 2);
	ft_putstr_fd(pb, 2);
	if (d->env)
		free_lst(d->env);
	if (d->envp)
		free_array(d->envp);
	g_sig.status = exit_code;
	exit(exit_code);
}

void	free_all(t_data *d, char **cmd)
{
	if (d->env != NULL)
		free_lst(d->env);
	d->env = NULL;
	if (cmd != NULL)
		free_array(cmd);
	cmd = NULL;
	if (d->pid_array)
	{
		free(d->pid_array);
		d->pid_array = NULL;
	}		
}
