/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:08:22 by ldes-cou@st       #+#    #+#             */
/*   Updated: 2021/12/02 22:07:17 by claclou          ###   ########.fr       */
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
			ft_memdel(&array[i]);
			i++;
		}
		free(array);
		array = NULL;
	}
}

void	free_lst(t_list *lst)
{
	t_list	*tofree;
	t_list	*head;	

	tofree = NULL;
	if (lst)
	{
		head = lst->next;
		while (head->next != NULL)
		{
			if (head->content)
			{
				free(head->content);
				head->content = NULL;
			}
			tofree = head;
			head = head->next;
			free(tofree);
			tofree = NULL;
		}
		free(head->content);
		head->content = NULL;
		free(head);
		head = NULL;
	}
}

void	free_exit(t_data *d, char *error, int exit_code, char *pb)
{
	ft_putstr_fd(error, 2);
	ft_putstr_fd(pb, 2);
	if (d->env != NULL)
		free_lst(d->env);
	if (d->envp != NULL)
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
