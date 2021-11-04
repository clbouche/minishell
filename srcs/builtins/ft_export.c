/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:37:04 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/04 15:16:26 by ldes-cou         ###   ########.fr       */
=======
/*   By: claclou <claclou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:37:04 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/04 15:29:33 by claclou          ###   ########.fr       */
>>>>>>> new_parsing
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** export a new variable takes 2 arg, the name of the new_var and the var
** without arg, it list env variables, in alphabetical order
*/
// void	change_var(t_list *var)
// {
// 	ft_putstr_fd(var->content, 1);
// }

//void is_there_an_egal
void	export_var(char **cmd, t_data *d, int j)
{
	t_list	*new_var;

	int		i;

	i = 0;
	while(cmd[j])
	{
		while (cmd[j][i])
		{
			if (cmd[j][i] == '=')
			{
				new_var = ft_lstnew(cmd[j]);
				ft_lstadd_back(&d->env, new_var);
				d->ret = SUCCESS;
			}
			i++;
		}
		j++;
	}
	g_sig.status = UNKNOWN_COMMAND;
	return ;
}

//=>export_var
///don't forget to free
//==> don't forget to sort alphabetically the variables
int	ft_export(char **cmd, t_data *d)
{
	//t_list	*tmp;
	//char	*name;
	int i;
	
	i = 1;
	if (cmd[i])
	{
		while (cmd[i])
		{	
			//name = find_name(cmd[1]);
			// tmp = check_exist_var(name, d);
			// if (tmp != NULL)
			// 	change_var(tmp);
			// else
			export_var(cmd, d, i);
			i++;
		}
		return (SUCCESS);
	}
	if (cmd[1] == NULL)
		print_export(d);
	free_array(cmd);
	g_sig.status = SUCCESS;
	return(g_sig.status);
}

void	print_export(t_data *d)
{
	t_list	*tmp;
	
	tmp = d->env;
	while (d->env != NULL) //print alphabetically
	{
		if (d->env->next == NULL)
		{
			printf("declare -x ");
			printf("\"%s\"\n", (char *)d->env->content);
		}
		else
		{
			printf("declare -x ");
			printf("\"%s\"\n", (char *)d->env->content);
		}
		d->env = d->env->next;
	}
	d->env = tmp;
}
