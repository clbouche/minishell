/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:15:48 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/10/12 13:46:08 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char **convert_env(t_data *d)
{
	char **env;
	t_list *tmp;
	int i;
	
	i = 0;
	tmp = d->env;
	env = malloc(sizeof(char *) * d->env_len + 1);
	while(tmp != NULL)
	{
		env[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	env[i] = NULL;
	// i = 0;
	// while(env[i] != NULL)
	// {
	// 	printf("[%i] == %s\n", i, env[i]);
	// 	i++;
	// }
	return(env);
}

void	get_path(char **cmd, t_data *d)
{
	char	*path;
	char	**paths;
	char	**envp;
	int		i;

	i = 0;
	path = NULL;
	paths = NULL;
	envp = convert_env(d);
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != 0)
			break ;
		i++;
	}

	//printf("%s\n", envp[i]);
	path = ft_substr(envp[i], 4, ft_strlen(envp[i]));
	paths = ft_split(path, ':');
	ft_memdel(&path);
	// free(path);
	// path = NULL;
	test_path(paths, cmd, envp);
}

void	test_path(char **paths, char **cmd, char **env)
{
	char	*bin;
	int		i;
	//(void)envp;
	
	i = 0;
	bin = NULL;
	while (paths[i] && bin == NULL)
	{
		bin = find_bin(cmd, paths, bin, i);
		if (access(bin, F_OK) == 0)
			break ;
		ft_memdel(&bin);
		// free(bin);
		// bin = NULL;
		i++;
	}
	free_array(paths);
	free(cmd[0]);
	cmd[0] = bin;
	// printf("%s\n", bin);
	// i = -1;
	// while(envp[++i] != NULL)
	// {
	// 	printf("%s\n", envp[i]);
	// }
	if (bin == NULL)
		exit(FAILURE);//free_exit(cmd);
	else
	{
		//puts("exec");
		execve(bin, cmd, env);
		exit(10);
	}
}

char	*find_bin(char **cmd, char **paths, char *bin, int i)
{
	bin = (char *)ft_calloc(sizeof(char), (ft_strlen(paths[i]) + ft_strlen(cmd[0]) + 2));
	ft_strcat(bin, paths[i]); //faire une fonction maison
	ft_strcat(bin, "/");
	ft_strcat(bin, cmd[0]);
	return (bin);
}
