/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou@student.42.fr <ldes-cou>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:15:48 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/09/30 14:13:06 by ldes-cou@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**get_path(char **cmd, t_data *d)
{
	int		i;
	int		j;
	char	*path;
	char	**paths;
	t_list *tmp;
	
	tmp = d->env;
	while(tmp->next != NULL)
	{
		if (!ft_strncmp(tmp->content, "PATH=", 5))
		{
			path = ft_substr(tmp->content, 5, (ft_strlen(tmp->content) - 5));
			paths = ft_split(path, ':');
			ft_memdel(path);
			//test_paths(paths);
		}
		tmp = tmp->next;
	}
	return(paths);
}
	// path = ft_strchr("PATH");
	// printf("%s\n", path);
	// //path = ft_substr(*envp, j, ft_strlen(*envp));
	// // paths = ft_split(path, ':');
	// // free(path);
	// // path = NULL;
	// // test_path(paths, cmd, envp, fd);

// void	test_path(char **paths, char **cmd, char **envp, int *fd)
// {
// 	char	*bin;
// 	int		i;

// 	i = 0;
// 	bin = NULL;
// 	while (paths[i] && bin == NULL)
// 	{
// 		bin = find_bin(cmd, paths, bin, i);
// 		if (access(bin, F_OK) == 0)
// 			break ;
// 		free(bin);
// 		bin = NULL;
// 		i++;
// 	}
// 	free_array(paths);
// 	free(cmd[0]);
// 	cmd[0] = bin;
// 	if (bin == NULL)
// 		free_exit(cmd, fd);
// 	else
// 	{
// 		execve(bin, cmd, envp);
// 		exit(0);
// 	}
// }

// char	*find_bin(char **cmd, char **paths, char *bin, int i)
// {
// 	bin = (char *)calloc(sizeof(char), (strlen(paths[i]) + strlen(cmd[0]) + 2));
// 	strcat(bin, paths[i]);
// 	strcat(bin, "/");
// 	strcat(bin, cmd[0]);
// 	return (bin);
// }
