#ifndef MINISHELL_H
# define MINISHELL_H

/*
** DEFINE
*/

#define RED "\001\033[31;1m\002"
#define GREEN "\001\e[1;32m\002"
#define RESET "\001\e[0m\002"
#define FAILURE 1
#define SUCCESS 0
//#define MAX 6
#define BUILTIN "{cd, echo, exit, export, pwd, unset}"
#define MAX 4096

/*
** LIBRAIRIES
*/

#include "libft/includes/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <dirent.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <curses.h>
#include <term.h>

/*
** ENUM
*/

typedef enum	s_builtin
{
	FT_CD = 2,
	FT_ECHO,
	FT_ENV,
	FT_EXPORT,
	FT_PWD,
	FT_UNSET,
	FT_EXIT,
}				t_builtin;

/*
** STRUCTURES
*/


typedef	struct s_data
{
	t_list	*env;
	char	opt;
	int		input;
	int		ouput;
	int 	ret;
}				t_data;

/*
** FUNCTIONS
*/

/*
** Init
*/

t_list	*init(t_data *data, char **envp);
void	init_datas(t_data *data);
t_list 	*get_env(t_list *env, char **envp);

/*
** Parsing
*/

char	**parser(char *line, t_data *data);
char	**complete_parser(char *line, t_data *data);
char	**split_cmd(char *line);
int		manage_redir(char **cmd, t_data *data);
char	*recup_filename(char *str);
int		recup_file_len(char *str);



/*
** Execution
*/

void	execute(char **cmd, t_data *data);


void	free_stack(t_list *top);
t_list	*delete_node(t_list *head, char *var);
t_list	*delete_head(t_list *head);

/*
** Built-in 
*/

int		ft_env(t_list *env);
t_list	*export_var(char **cmd);
int		ft_export(char **cmd);
int		ft_unset(char **cmd);
int		ft_pwd(void);
void	ft_exit(void);
int		ft_cd(char **cmd);
int		ft_echo(char **cmd);
int		is_builtins(char **cmd);
void	exec_builtin(int ret, char **cmd, t_data *d);


/*
** Free
*/

void	free_stack(t_list *top);
t_list	*delete_node(t_list *head, char *var);
t_list	*delete_head(t_list *head);
void	free_lst(t_list *lst);
void	free_exit(t_list *lst, char *error);

void	get_path(char **cmd, char **envp);
void	tests(t_list *env, char **cmd);

#endif
