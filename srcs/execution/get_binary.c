/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:15:48 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/11/03 17:45:47 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **get_absolute_path(char **cmd, t_data *d)
{
	char *name;
	char **path;

	path = NULL;
	name = NULL;
	*cmd += 1;
	name = ft_strcpy(*cmd, name);
	path[0] = ft_strjoin(d->pwd, name);
	free_array(cmd);
	return(path);
}

void convert_env(t_data *d)
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

