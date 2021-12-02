/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:37:31 by clbouche          #+#    #+#             */
/*   Updated: 2021/12/02 17:43:05 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*delete_head(t_list *head)
{
	t_list	*new_head;

	new_head = head->next;
	free(head->content);
	free(head);
	head = NULL;
	return (new_head);
}

static t_list	*delete_middle(t_list *h, t_list *hn, char *name)
{	
	h->next = hn->next;
	free(hn->content);
	free(hn);
	hn = NULL;
	ft_memdel(&name);
	return (h);
}

static t_list	*delete_last(t_list *h, t_list *hn, char *name)
{
	h->next = NULL;
	free(hn->content);
	free(hn);
	hn = NULL;
	ft_memdel(&name);
	return (h);
}

t_list	*delete_node(t_list *head, char *var)
{
	t_list	*h;
	t_list	*hn;
	char	*name;

	if (!(ft_strncmp(var, head->content, (ft_strlen(var)))))
		head = delete_head(head);
	h = head;
	hn = head->next;
	while (hn->next != NULL)
	{
		h = h->next;
		hn = hn->next;
		name = find_name(hn->content);
		if (!(ft_strncmp(var, name, (ft_strlen(name)))))
		{
			if (hn->next == NULL)
				h = delete_last(h, hn, name);
			else
				h = delete_middle(h, hn, name);
			return (head);
		}
		free(name);
	}
	return (head);
}

t_list	*ft_unset(char **cmd, t_data *d)
{
	int	i;

	i = 1;
	while (cmd[i])
	{
		unset_var(cmd[i], d);
		i++;
	}
	return (d->env);
}
