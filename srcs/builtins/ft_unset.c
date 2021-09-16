/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:37:31 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/16 15:59:09 by ldes-cou@st      ###   ########.fr       */
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

void ft_unset()
{
    free_stack(env);
}


void	free_stack(t_node *top)
{
	t_node	*head;
	t_node	*tofree;

	if (top)
	{
		head = top->next;
		while (head->next != NULL)
		{
			tofree = head;
			head = head->next;
			free(tofree);
			tofree = NULL;
		}
		free(head);
	}
}