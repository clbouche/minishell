/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:37:31 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/29 16:33:21 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
            puts("here");
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
        else if (hn->next == NULL)
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
