/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:25:00 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/18 10:51:14 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** change the working directory
** -> utilisation de chdir
*/

int	ft_cd(char **cmd)
{
	char	*path;

	if (cmd[1] == NULL)
		path = ft_strdup(getenv("HOME"));
	else
		path = ft_strdup(cmd[1]);
	if (chdir(path) == -1)
	{
		perror("cd");
		free(path);
		g_sig.status = FAILURE;
		return (g_sig.status);
	}
	free(path);
	free_array(cmd);
	return (g_sig.status);
}
