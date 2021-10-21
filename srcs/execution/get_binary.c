/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:15:48 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/10/21 14:08:19 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void convert_env(t_data *d)
{
	t_list *tmp;
	int i;
	
	i = 0;
	tmp = d->env;
	
	d->envp = malloc(sizeof(char *) * (d->env_len + 1));
	while(tmp != NULL)
	{
		d->envp[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}

	d->envp[i] = NULL;
}

char *test_path(char **cmd, char **paths, char *bin, int i)
{
	bin = (char *)ft_calloc(sizeof(char), (ft_strlen(paths[i]) + ft_strlen(cmd[0]) + 2));
	ft_strcat(bin, paths[i]); //faire une fonction maison
	ft_strcat(bin, "/");
	ft_strcat(bin, cmd[0]);
	return (bin);
}

char *find_bin(char **paths, char **cmd)
{
	char *bin;
	int		i;
	
	i = 0;
	bin = NULL;
	while (paths[i] && bin == NULL)
	{
		bin = test_path(cmd, paths, bin, i);
		if (access(bin, F_OK) == 0)
			break ;
		ft_memdel(&bin);
		i++;
	}
	free_array(paths);
	return(bin);
}

char	**get_path(t_data *d)
{
	char	*path;
	char	**paths;
	int		i;

	i = 0;
	path = NULL;
	paths = NULL;
	convert_env(d);
	while (d->envp[i])
	{
		if (ft_strnstr(d->envp[i], "PATH=", 5) != 0)
			break ;
		i++;
	}
	path = ft_substr(d->envp[i], 4, ft_strlen(d->envp[i]));
	paths = ft_split(path, ':');
	ft_memdel(&path);
	return (paths);
}

void	exec_bin(char **cmd, char *bin, t_data *d)
{
	if (bin == NULL)
		free_exit(d, cmd[0], 127);//exit(127);//free_exit(cmd);
	free(cmd[0]);
	cmd[0] = bin;
	g_sig.prog = 1;
	execve(bin, cmd, d->envp);
	exit(FAILURE);
}