/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:37:31 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/20 16:38:26 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_unset_arg(t_list *env, char *name)
{
    t_list *tmp;

    tmp = env;
    while (tmp != NULL)
    {
        if (!ft_strncmp(name, env->content, (ft_strlen(name))))
            break;
        tmp = tmp->next;
    }
    
    //ft_lstdelone(tmp, );
}

/*to delete a node check the position of the node 
    ==> if first node deplace the ptr to the 2nd node
    ==> if in the middle, deplace the ptr to next of the precedent node to the next node
    ==> if in the end move ptr of the previous to NULL 