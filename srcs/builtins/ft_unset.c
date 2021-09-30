/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:37:31 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/30 11:34:41 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_list *delete_head(t_list *head)
{
    t_list *new_head;

    new_head = head->next;
    free(head);
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
	printf("cmd[1] = %s\n", cmd[1]);
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
	
	h = head;
	hn = head->next;
	if (!(ft_strncmp(var, h->content, (ft_strlen(var)))))
		head = delete_head(head);
	while(hn != NULL)
	{
		if (!(ft_strncmp(var, hn->content, (ft_strlen(var)))))
		{
			if (hn->next == NULL)
				h = delete_last(h, hn);
			else
				h = delete_middle(h, hn);
		}
		h = h->next;
		hn = hn->next;   
	}
	return (head); 
}


/*to delete a node check the position of the node 
	==> if first node deplace the ptr to the 2nd node
	==> if in the middle, deplace the ptr to next of the precedent node to the next node
	==> if in the end move ptr of the previous to NULL 
*/
