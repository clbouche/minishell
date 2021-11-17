/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:37:04 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/16 16:00:58 by clbouche         ###   ########.fr       */
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
	//bool	exist_var;
	int		i;
	char	**var_unset;

	i = 0;
	var_unset = malloc(sizeof(char *) * 2);
	if (!var_unset)
		exit(EXIT_FAILURE);
	while (cmd[j][i])
	{
		if (cmd[j][i] == '=')
		{
			var_unset[1] = ft_substr(cmd[j], 0, i);
			ft_unset(var_unset, d);
			new_var = ft_lstnew(cmd[j]);
			ft_lstadd_back(&d->env, new_var);
			d->ret = SUCCESS;
		}
		i++;
	}
		j++;
	g_sig.status = UNKNOWN_COMMAND;
	return ;
}

//=>export_var
///don't forget to free
//==> don't forget to sort alphabetically the variables
int	ft_export(char **cmd, t_data *d)
{
	int i;
	
	i = 1;
	if (cmd[i])
	{
		if (ft_isdigit(cmd[i][0] == 1))
		{
			ft_putstr_fd("not a valid identifier", 2);
			g_sig.status = FAILURE;
			return(g_sig.status);
		}
		printf("return ft_isdigit == %i\n", ft_isdigit(cmd[i][0]));
		while (cmd[i])
		{	
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
