/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:56:26 by clbouche          #+#    #+#             */
/*   Updated: 2021/12/01 09:48:00 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** change the working directory
** -> utilisation de chdir
*/

void	change_oldpwd(t_data *d, char *old_pwd)
{
	t_list	*new_oldpwd;

	unset_var("OLDPWD", d);
	old_pwd = ft_strjoin("OLDPWD=", old_pwd);
	new_oldpwd = ft_lstnew(old_pwd);
	old_pwd = NULL;
	free(old_pwd);
	ft_lstadd_back(&d->env, new_oldpwd);
}

void	change_pwd(t_data *d)
{
	t_list	*new_pwd;
	char	*pwd;
	char	path[MAX];

	unset_var("PWD", d);
	pwd = ft_strjoin("PWD=", getcwd(path, MAX));
	new_pwd = ft_lstnew(pwd);
	pwd = NULL;
	free(pwd);
	ft_lstadd_back(&d->env, new_pwd);
}

int	execute_cd(char *path, t_data *d, char **cmd)
{
	char	*old_pwd;
	char	dir[MAX];

	old_pwd = getcwd(dir, MAX);
	if (chdir(path) == -1)
	{
		perror("cd");
		free(path);
		g_sig.status = FAILURE;
		return (g_sig.status);
	}
	change_pwd(d);
	change_oldpwd(d, old_pwd);
	free_array(cmd);
	return (g_sig.status);
}

int	ft_cd(char **cmd, t_data *d)
{
	char	*path;

	path = NULL;
	if (cmd[1] && cmd[2])
	{
		ft_putstr_fd("cd : too many arguments\n", 1);
		return (FAILURE);
	}
	else if (cmd[1] == NULL)
	{
		path = getenv("HOME");
		if (path == NULL)
		{
			ft_putstr_fd("cd : HOME not set\n", 1);
			return (FAILURE);
		}
	}
	else if (cmd[1])
		path = cmd[1];
	return (execute_cd(path, d, cmd));
}
