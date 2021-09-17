/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:37:31 by clbouche          #+#    #+#             */
/*   Updated: 2021/09/16 16:53:10 by ldes-cou@st      ###   ########.fr       */
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

void ft_unset(t_list *env)
{
    free_stack(env);
}


void	free_stack(t_list *top)
{
	t_list	*head;
	t_list	*tofree;

	if (top)
	{
		head = top->next;
		while (head->next != NULL)
		{
			tofree = head;
            printf("%p\n", tofree);
			head = head->next;
			free(tofree);
			tofree = NULL;
		}
		free(head);
	}
}