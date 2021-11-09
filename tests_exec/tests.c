# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <signal.h>
# include <errno.h>

char	*find_bin(char **cmd, char **paths, char *bin, int i)
{
	bin = (char *)calloc(sizeof(char), (strlen(paths[i]) + strlen(cmd[0]) + 2));
	strcat(bin, paths[i]);
	strcat(bin, "/");
	strcat(bin, cmd[0]);
	return (bin);
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
		free(bin);
		bin = NULL;
		i++;
	}
	//free_array(paths);
	free(cmd[0]);
	cmd[0] = bin;
	if (bin == NULL)
		puts("error bin");//free_exit(cmd, fd);
	else
	{
		execve(bin, cmd, envp);
		exit(0);
	}
}
void	get_path(char **cmd, char **envp)
{
	int		i;
	int		j;
	char	*path;
	char	**paths;

	i = 0;
	j = 0;
	// while (*envp)
	// {
	// 	if (ft_strnstr(*envp, "PATH", 4) != 0)
	// 		break ;
	// 	envp++;
	// }
	// while (envp[i][j] != '/')
	// 	j++;
	path = 
	paths = strtok(path, ':');
	free(path);
	path = NULL;
	test_path(paths, cmd, envp);
}



int main(int ac, char **argv, char **envp)
{
    (void)ac;
    int *fd;
    int pid;
    char **cmd;

    fd[1] = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 00700);
    if (fd < 0)
        exit(1);
    pid = fork();
    if (pid < 0)
        exit(1);
    else if (pid == 0)
    {
        cmd = NULL;
	    cmd = strtok(argv[1], " ");
        dup2(fd[1], 1);
        close(fd[1]);
        get_path(cmd, envp);
    }
}
