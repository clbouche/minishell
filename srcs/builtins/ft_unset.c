/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:37:31 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/12 16:10:45 by ldes-cou         ###   ########.fr       */
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

static t_list	*delete_middle(t_list *h, t_list *hn, char *name)
{
	
	h->next = hn->next;
	free(hn);
	hn = NULL;
	ft_memdel(&name);
	return (h);
}

static t_list	*delete_last(t_list *h, t_list *hn, char *name)
{
	h->next = NULL;
 	free(hn);
	hn = NULL;
	ft_memdel(&name);
	return(h);
}

t_list  *ft_unset(char **cmd, t_data *d)
{
	t_list *tmp;
	char *name_var;
	int pos;
	
	pos = 0;
	tmp = d->env;
	while (tmp != NULL)
	{
		name_var = find_name(tmp->content);
		if (ft_strncmp(cmd[1], name_var, (ft_strlen(name_var))) == 0)
		{
			d->env = delete_node(d->env, cmd[1]);
			d->ret = SUCCESS;
			return(d->env);
			free(name_var);
		}
		tmp = tmp->next;
		pos++;
	}
	d->ret = FAILURE;
	free(name_var);
	return(NULL);
}

t_list *delete_node(t_list *head, char *var)
{
	t_list *h;
	t_list *hn;
	char *name;
	
	if (!(ft_strncmp(var, head->content, (ft_strlen(var)))))
		head = delete_head(head);
	h = head;
	hn = head->next;
	while(hn->next != NULL)
	{
		h = h->next;
		hn = hn->next;
		name = find_name(hn->content);
		if (!(ft_strncmp(var, name, (ft_strlen(name)))))
		{
			if (hn->next == NULL)
			{
				h = delete_last(h, hn, name);
				return(head);
			}
			else
			{
				h = delete_middle(h, hn, name);
				return(head);
			}
		}
	}
	return (head);
}
