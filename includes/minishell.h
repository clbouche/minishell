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
#define TRUE 0
#define FALSE 1
#define OUT 1
#define IN 2
#define BOTH 3
#define MAX 4096
#define UNKNOWN_COMMAND 127 

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
#include <stdbool.h>
#include <errno.h>
/*
** ENUM
*/


typedef struct	s_sig
{
	int				status;
	pid_t			pid;
	int 			prog;
}				t_sig;

extern t_sig g_sig;

typedef enum	s_builtin
{
	FT_CD = 2,
	FT_ECHO,
	FT_ENV,
	FT_EXPORT,
	FT_PWD,
	FT_UNSET,
	FT_EXIT
}				t_builtin;
/*
** STRUCTURES
*/


typedef	struct s_data
{
	t_list	*env;
	int		file_out;
	int		file_in;
	int		std_out;
	int		std_in;
	int 	ret;
	int		env_len;
	char **	envp;
	t_node	*lexer;
	t_dlist	*lst;
	bool	pipe;
	bool	redir;
	bool	redir_in;
	bool	redir_out;
}				t_data;

/*
** Init
*/

t_list	*init(t_data *data, char **envp);
void	init_datas(t_data *data);

/*
** Parsing
*/

int		parser(char *line, t_data *data);
char	*create_input(char *line);
char	**split_cmd(char *line);
int		parse_to_exec(char *input, t_data *data);

/*
** redirections 
*/
void	manage_redir(char *input, int i, t_data *data);
void	redir_read_input(char *str, t_data *data);
void	heredoc_loop(char *delimiter, t_data *data, int *heredoc_pipe);
char	*define_delimiter(char *str);
void	redir_input(char *str, t_data *data);
void	redir_output_append(char *str, t_data *data);
void	redir_ouput(char *str, t_data *data);
char	*recup_filename(char *str);
int		recup_file_len(char *str);

/*
** expands
*/
char	*manage_expand(char *line, t_data *data);
char    *manage_variable(char *line, t_data *data);
int		check_append(char *line);

/*
** utils parsing
*/
bool	spe_case(char c);
bool	check_char(char c);
bool	check_char_begin(char c);
bool	check_char_file(char c);
t_list *check_exist_var(char *name, t_data *data);

/*
** Execution
*/
void	close_fds(t_data *data);
void	execute(char **cmd, t_data *data);
void 	exec_builtin(char **cmd, t_data *d);
void 	exec_simple(char  **cmd, t_data *d);
void	exec_bin(char **cmd, char *bin, t_data *d);
void	exec_pipes(char *line, char *new_input, t_data *data);
int 	is_builtins(char **cmd);
void	exec(char **cmd, t_data *d);
int		redirect(t_data *d);

/*
** find_path
*/

// char *find_bin(char **paths, char **cmd, char **env);
char 	*test_path(char **cmd, char **paths, char *bin, int i);
char	**get_path(t_data *d);
char 	*find_bin(char **paths, char **cmd);

/*
** init
*/
t_list		*delete_node(t_list *head, char *var);
t_list		*get_env(t_data *d, char **envp);
t_dlist		*init_list(t_dlist *list);
void		print_dlist(t_dlist *lst);
t_list		*init(t_data *d, char **envp);
t_list		*set_lvl(t_list *env, char * lvl);

/*
** Built-in 
*/

void	ft_env(t_data *d, char **cmd);
char	*find_var(char *name);
char	*find_name(char *var);
void	export_var(char **cmd, t_data *d);
int		ft_export(char **cmd, t_data *d);
void	print_export(t_data *d);
t_list	*ft_unset(char **cmd, t_data *d);
int		ft_pwd(void);
//int		ft_exit(char **cmd, t_data *d);
int		ft_exit();
int		ft_cd(char **cmd);
int		ft_echo(char **cmd, t_data *d);

/*
** Free
*/

void	free_stack(t_list *top);
void	free_array(char **array);
void	free_lst(t_list *lst);
void	free_exit(t_data *d, char *error, int exit_code, char *pb);
void	free_all(t_data *d);
void	tests(t_list *env, char **cmd);
void	opening_error(char *error);

/*
** signals
*/

void sig_handler(int signo);

#endif
