/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:09:16 by ldes-cou@         #+#    #+#             */
/*   Updated: 2021/11/23 09:09:16 by clbouche         ###   ########.fr       */
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
	while (*var != '=')
		var++;
	var++;
	lvl = ft_atoi(var);
	new_lvl = ft_itoa(lvl + 1);
	free(tmp);
	var = ft_strjoin("SHLVL=", new_lvl);
	free(new_lvl);
	return (var);
}

t_list	*env_null(t_data *d, int shell_level)
{
	t_list *new;
	char 	*tmp;
	char	path[MAX];

	getcwd(path, MAX);
	tmp = ft_strjoin("PWD=", path);
	new = ft_lstnew(tmp);
	ft_lstadd_back(&d->env, new);
	new = ft_lstnew("_=/usr/bin/env");
	ft_lstadd_back(&d->env, new);
	tmp = ft_strjoin("SHLV=", ft_itoa(shell_level++));
	new = ft_lstnew(tmp);
	ft_lstadd_back(&d->env, new);
	return (d->env);
}

t_list	*get_env(t_data *d, char **envp)
{
	t_list	*new;
	char	*var;
	int		i;
	static int shell_level = 1;

	new = NULL;
	var = NULL;
	i = -1;
	if (*envp == NULL)
		env_null(d, shell_level);
	while (envp[++i])
	{
		var = ft_strdup(envp[i]);
		if (ft_strncmp(var, "SHLVL", 5) == 0)
			var = change_shlvl(var);
		if (var == NULL)
			free_exit(d, "env", 1, "malloc error");
		new = ft_lstnew(var);
		if (new == NULL)
			free_exit(d, "env", 1, "chained list error");
		ft_lstadd_back(&d->env, new);
		d->env_len++;
	}
	return (d->env);
}
