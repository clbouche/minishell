/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:25:00 by clbouche          #+#    #+#             */
/*   Updated: 2021/10/18 16:55:51 by ldes-cou         ###   ########.fr       */
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

	path = NULL;
	if (cmd[1] == NULL)
		return (FAILURE);
	path = ft_strdup(cmd[1]);
	if (chdir(path) == -1)
	{
		perror("cd");
		free(path);
		return (FAILURE);
	}
	free(path);
	free_array(cmd);
	return (SUCCESS);
}
