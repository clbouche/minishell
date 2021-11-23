/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:25:00 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/23 12:15:57 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** change the working directory
** -> utilisation de chdir
*/

/*void	change_oldpwd(t_data *d)
{
	
}
*/
/*void	change_pwd(t_data *d, char **cmd)
{
	
	
}*/


int	ft_cd(char **cmd, t_data *d)
{
	char	*path;

	(void)d;
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
	if (chdir(path) == -1)
		{
			perror("cd");
			free(path);
			g_sig.status = 1;
			return (FAILURE);
		}
	//else if (ft_strcmp(cmd[1], "-") == 0)
	//	cd_oldpwd();
	//change_oldpwd(data, cmd[1]);
	//change_pwd(d, cmd);
	free_array(cmd);
	g_sig.status = 0;
	return (SUCCESS);
}

//besoin de mettre a jour le OLDPWD a chaque fois qu'on fait cd 
//besoin aussi de mettre a jour le PWD
