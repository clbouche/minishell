/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:37:31 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/27 15:26:37 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_unset(char **cmd, t_data *d)
{
    t_list *tmp;

    int pos;
    char *var;

    var = cmd[1];
    pos = 0;
    tmp = d->env;
    while (tmp != NULL)
    {
        if (ft_strncmp(var, tmp->content, (ft_strlen(var))) == 0)
        {
			d->env = delete_node(d->env, var);
			return(FAILURE);
		}
        tmp = tmp->next;
        pos++;
    }
    return (SUCCESS);
}

t_list *delete_node(t_list *head, char *var)
{
    t_list *h;
    t_list *hn;
    
    h = head;
    hn = head->next;
    if (ft_strncmp(var, h->content, (ft_strlen(var))) == 0)
    {
        head = hn;
        free(h);
    }
    else
    {
        if (ft_strncmp(var, h->content, (ft_strlen(var))) == 0)
        {
            h = h->next;
            hn = hn->next;
        }
        if (hn->next == NULL)
        {
            h->next = NULL;
            free(h);
        }
        else
		{
            h->next = hn->next;
            free(hn);
		}
    }
	//printf("head ==== %s\n", head->content);
    return (head);
}

// t_list *delete_head(t_list *head)
// {
//     t_list *new_head;

//     new_head = head->next;
//     free(head);
//     return(new_head); 
// }
/*to delete a node check the position of the node 
    ==> if first node deplace the ptr to the 2nd node
    ==> if in the middle, deplace the ptr to next of the precedent node to the next node
    ==> if in the end move ptr of the previous to NULL 
*/
