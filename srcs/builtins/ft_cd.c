/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:25:00 by clbouche          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/29 13:18:18 by ldes-cou         ###   ########.fr       */
=======
/*   Updated: 2021/11/29 14:50:53 by clbouche         ###   ########.fr       */
>>>>>>> 983f42dfd8a1a0b8b3e39b1bf4891b1ab11aa124
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
	ft_lstadd_back(&d->env, new_oldpwd);
}

void	change_pwd(t_data *d)
{
	t_list	*new_pwd;
	char	*pwd;

	unset_var("PWD", d);
	pwd = ft_strjoin("PWD=", getcwd(NULL, 0));
	new_pwd = ft_lstnew(pwd);
	pwd = NULL;
	ft_lstadd_back(&d->env, new_pwd);
}

int	ft_cd(char **cmd, t_data *d)
{
	char	*path;
	char	*old_pwd;

	path = NULL;
	old_pwd = getcwd(NULL, 0);
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
