/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:15:48 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/11/16 10:45:00 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	struct  stat stat_b;
	
	i = 0;
	bin = NULL;
	if (paths)
	{
		while (paths[i] && bin == NULL)
		{
			bin = test_path(cmd, paths, bin, i);
			if (stat(bin, &stat_b) == 0)
				break ;
			ft_memdel(&bin);
			i++;
		}
	}
	//free_array(paths);
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
	if (d->envp[i] == NULL)
		return(NULL);
	path = ft_substr(d->envp[i], 4, ft_strlen(d->envp[i]));
	paths = ft_split(path, ':');
	ft_memdel(&path);
	return (paths);
}

