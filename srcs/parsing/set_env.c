/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:09:16 by ldes-cou@         #+#    #+#             */
/*   Updated: 2021/09/16 14:42:41 by ldes-cou@st      ###   ########.fr       */
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
	home = ft_lstnew(ft_strjoin("HOME=", getenv("HOME")));
	old_pwd = ft_lstnew(ft_strjoin("OLDPWD=", getenv("OLDPWD")));
	pwd = ft_lstnew(ft_strjoin("PWD=", getenv("PWD")));
	shlvl = ft_lstnew(ft_strjoin("SHLVL=", getenv("SHLVL")));
	ft_lstadd_back(&env, home);
	ft_lstadd_back(&env, old_pwd);
	ft_lstadd_back(&env, pwd);
	ft_lstadd_back(&env, shlvl);
	/**tests**/
	puts(RED"ft_env"RESET); 
	ft_env(env);
	puts(RED"ft_export_var"RESET); ft_export_var(env, "PAPOU", "vour");
	puts(RED"ft_export"RESET); ft_export(env);
	
}
//===> don't forget to free
