/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:37:31 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/12 14:11:48 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list *delete_head(t_list *head)
{
    t_list *new_head;

    new_head = head->next;
    free(head);
	head = NULL;
    return(new_head); 
}

static t_list	*delete_middle(t_list *head, t_list *hn)
{
	
	head->next = hn->next;
	free(hn);
	return(head);
}

static t_list	*delete_last(t_list *head, t_list *hn)
{
	head->next = NULL;
	free(hn);
	return(head);
}

t_list  *ft_unset(char **cmd, t_data *d)
{
	t_list *tmp;

	int pos;
	
	pos = 0;
	tmp = d->env;
	while (tmp != NULL)
	{
		if (ft_strncmp(cmd[1], tmp->content, (ft_strlen(cmd[1]))) == 0)
		{
			d->env = delete_node(d->env, cmd[1]);
			d->ret = SUCCESS;
			return(d->env);
		}
		tmp = tmp->next;
		pos++;
	}
	d->ret = FAILURE;
	return(NULL);
}

t_list *delete_node(t_list *head, char *var)
{
	t_list *h;
	t_list *hn;
	
	if (!(ft_strncmp(var, head->content, (ft_strlen(var)))))
		head = delete_head(head);
	h = head->next;
	hn = head->next->next;
	while(hn->next->next != NULL)
	{
		if (!(ft_strncmp(var, hn->content, (ft_strlen(var)))))
		{
			if (hn->next == NULL)
			{
				h = delete_last(h, hn);
				return(head);
			}
			else
			{
				h = delete_middle(h, hn);
				return(head);
			}
		}
		h = h->next;
		hn = hn->next;
	}
	return (head); 
}
