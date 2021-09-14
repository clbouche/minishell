/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@ <ldes-cou@student42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:09:16 by ldes-cou@         #+#    #+#             */
/*   Updated: 2021/09/14 16:45:11 by ldes-cou@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minishell.h"

void get_env(char **envp, t_list *env)
{
	t_list *home;
	t_list *old_pwd;
	t_list *pwd;
	t_list *shlvl;
	
	env = ft_lstnew(ft_strjoin("PATH=", getenv("PATH")));
	home = ft_lstnew(ft_strjoin("HOME=", getenv("HOME=")));
	old_pwd = ft_lstnew(ft_strjoin("OLDPWD=", getenv("OLDPWD=")));
	pwd = ft_lstnew(ft_strjoin("PWD=", getenv("PWD=")));
	shlvl = ft_lstnew(ft_strjoin("SHLVL=", getenv("SHLVL=")));
	ft_lstadd_back(&env, home);
	ft_lstadd_back(&env, old_pwd);
	ft_lstadd_back(&env, pwd);
	ft_lstadd_back(&env, shlvl);
	//print_env(env);
}

void print_env(t_list *env)
{
	t_list *tmp;
	
	tmp = env;
	while(env != NULL)
	{
		printf("%s\n", env->content);
		env = env->next;
	}
	env = tmp;
}

