/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:41:59 by claclou           #+#    #+#             */
/*   Updated: 2021/09/28 15:32:18 by claclou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		choose_action(t_dlist *lst)
{
	t_node *temp;

	temp = lst->begin;
	if (!ft_strcmp(temp->value, "echo"))
		ft_echo(temp->token.data , ' ', 1);
	/*else if (!ft_strcmp(inputs[0], "pwd"))
		ft_pwd(data);
	else if (!ft_strcmp(inputs[0], "cd"))
		ft_cd(inputs, data);
	else if (!ft_strcmp(inputs[0], "env"))
		ft_env(data->env);
	else if (!ft_strcmp(inputs[0], "exit"))
		ft_exit(inputs, data);
	else if (!ft_strcmp(inputs[0], "export"))
		ft_export(inputs, data);
	else if (!ft_strcmp(inputs[0], "unset"))
		ft_unset(inputs, data);
	else
	{
		ft_exec(inputs, data);
	}*/
}