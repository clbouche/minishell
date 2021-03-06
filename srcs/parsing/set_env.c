/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:09:16 by ldes-cou@         #+#    #+#             */
/*   Updated: 2021/12/02 16:41:26 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*change_shlvl(char *var)
{
	int		lvl;
	char	*new_lvl;
	char	*tmp;

	lvl = 0;
	tmp = var;
	while (*tmp != '=')
		tmp++;
	tmp++;
	lvl = ft_atoi(tmp);
	free(var);
	new_lvl = ft_itoa(lvl + 1);
	var = ft_strjoin("SHLVL=", new_lvl);
	free(new_lvl);
	return (var);
}

t_list	*env_null(t_data *d)
{
	t_list	*new;
	char	*tmp;
	char	path[MAX];

	tmp = ft_strjoin("PWD=", getcwd(path, MAX));
	new = ft_lstnew(tmp);
	ft_lstadd_back(&d->env, new);
	tmp = ft_strdup("SHLV=1");
	new = ft_lstnew(tmp);
	ft_lstadd_back(&d->env, new);
	return (d->env);
}

t_list	*get_env(t_data *d, char **envp)
{
	t_list	*new;
	char	*var;
	int		i;

	var = NULL;
	i = -1;
	if (*envp == NULL)
		env_null(d);
	while (envp[++i])
	{
		var = ft_strdup(envp[i]);
		if (ft_strncmp(var, "SHLVL", 5) == 0)
			var = change_shlvl(var);
		new = ft_lstnew(var);
		if (new == NULL)
			free_exit(d, "env", 1, "chained list error");
		ft_lstadd_back(&d->env, new);
		d->env_len++;
	}
	return (d->env);
}
