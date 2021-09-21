/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:37:31 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/21 10:44:12 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

t_list	*ft_unset(t_list *env, char *var)
{
    t_list *tmp;
    int pos;

    pos = 0;
    tmp = env;
    while (tmp != NULL)
    {
        if (ft_strncmp(var, tmp->content, (ft_strlen(var))) == 0)
        {
			env = delete_node(env, var);
			return(env);
		}
        tmp = tmp->next;
		puts("ici ?");
        pos++;
    }
    return (env);
}

t_list *delete_node(t_list *head, char *var)
{
    t_list *h;
    t_list *hn;
    
    h = head;
    hn = head->next;
	puts("la");
    if (ft_strncmp(var, h->content, (ft_strlen(var))) == 0)
    {
        head = hn;
        free(h);
    }
    else
    {
		puts("lolo");
        if (!ft_strncmp(var, h->content, (ft_strlen(var))))
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
            hn->next = h->next;
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