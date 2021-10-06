/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:15:48 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/10/01 12:13:28 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char **convert_env(t_data *d)
{
	char **env;
	t_list *tmp;
	int i;
	
	i = 0;
	tmp = d->env;
	env = malloc(sizeof(char *) * d->env_len);
	while(tmp != NULL)
	{
		env[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	// i = 0;
	// while(i < 52)
	// {
	// 	printf("[%i] == %s\n", i, env[i]);
	// 	i++;
	// }
	return(env);
}

void	get_path(char **cmd, t_data *d)
{
	int		i;
	int		j;
	char	*path;
	char	**paths;
	char	**envp;

	i = 0;
	j = 0;
	envp = convert_env(d);
	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH", 4) != 0)
			break ;
		envp++;
	}
	while (envp[i][j] != '/')
		j++;
	path = ft_substr(*envp, j, ft_strlen(*envp));
	paths = ft_split(path, ':');
	ft_memdel(path);
	test_path(paths, cmd, envp);
}

void	test_path(char **paths, char **cmd, char **envp)
{
	char	*bin;
	int		i;

	i = 0;
	bin = NULL;
	while (paths[i] && bin == NULL)
	{
		bin = find_bin(cmd, paths, bin, i);
		if (access(bin, F_OK) == 0)
			break ;
		ft_memdel(bin);
		i++;
	}
	free_array(paths);
	free(cmd[0]);
	cmd[0] = bin;
	if (bin == NULL)
		exit(FAILURE);//free_exit(cmd);
	else
	{
		puts("exec == ");
		execve(bin, cmd, envp);
		//exit(0);
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
