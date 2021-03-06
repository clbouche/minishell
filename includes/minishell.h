/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:32:28 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/12/03 09:44:18 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** DEFINE
*/

# define RED "\001\033[31;1m\002"
# define GREEN "\001\e[1;32m\002"
# define RESET "\001\e[0m\002"
# define FAILURE 1
# define SUCCESS 0
# define OUT 1
# define IN 2
# define BOTH 3
# define MAX 4096
# define UNKNOWN_COMMAND 127 
# define INVALID_OPTION 2

/*
** LIBRAIRIES
*/

# include "libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <dirent.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <stdbool.h>
# include <errno.h>
/*
** ENUM
*/

typedef struct s_sig
{
	int		status;
	pid_t	pid;
	int		prog;
	int		sigint;
	int		sigquit;
	bool	heredoc;	
}				t_sig;

extern t_sig	g_sig;

typedef enum s_builtin
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

typedef struct s_redir
{
	bool	r;
	bool	r_in;
	bool	r_out;
	bool	pipe_in;
	bool	pipe_out;
	bool	bad_r;
	int		count_in;
	int		count_out;
	int		count_append;
	int		count_heredoc;
}				t_redir;

typedef struct s_data
{
	t_list	*env;
	pid_t	*pid_array;
	int		pid;
	int		pipes;
	int		fds[2];
	int		file_out;
	int		file_in;
	int		std_out;
	int		std_in;
	int		ret;
	int		env_len;
	char	**envp;
	t_node	*lexer;
	t_dlist	*lst;
	char	pwd[MAX];
	bool	have_path;
	bool	pipe;
	bool	piped;
	bool	heredoc_int;
	t_redir	*redir;
}				t_data;

/*
** Init
*/

t_list	*set_lvl(t_list *env, char *lvl);
void	init_datas(t_data *data);
t_list	*init_env(t_data *data, char **envp);
t_dlist	*init_list(t_dlist *list);
t_list	*get_env(t_data *d, char **envp);
void	malloc_pid_array(t_data *data);
t_list	*delete_node(t_list *head, char *var);
void	print_dlist(t_dlist *lst);

/*
** Parsing
*/

int		parser(char *line, t_data *data);
char	*clean_input(char *line);
char	**split_cmd(char *line);
int		parse_to_exec(char *input, t_data *data);

/*
** redirections 
*/
void	count_redir(char *line, t_data *data);
char	*check_redir(char *line, t_data *data);
void	manage_redir(char *input, int i, t_data *data);
void	redir_heredoc(char *str, t_data *data);
void	heredoc_loop(char *delimiter, t_data *data);
char	*define_delimiter(char *str);
void	redir_input(char *str, t_data *data);
void	redir_output_append(char *str, t_data *data);
void	redir_output(char *str, t_data *data);
char	*recup_filename(char *str);
int		recup_file_len(char *str);

/*
** expands
*/
char	*manage_expand(char *line, int i, t_data *data);
char	*manage_variable(char *line, int i, t_data *data);
int		check_append(char *line);

/*
** utils parsing
*/
int		is_numeric(char *input);
bool	spe_case(char c);
bool	check_char(char c);
bool	check_char_begin(char c);
bool	check_char_file(char c);
bool	check_exist_var(char *arg, int i, t_data *data);

/*
** Execution
*/
void	add_to_array(t_data *d, pid_t pid);
void	count_childs(char *cmd, t_data *data);
void	execute(char **cmd, t_data *data);
void	exec_builtin(char **cmd, t_data *d);
void	exec_simple(char **cmd, t_data *d);
char	*exec_pipes(char *line, char *new_input, t_data *data);
int		is_builtins(char **cmd);
void	wait_for_childs(t_data *data);

/*
** manage_fds
*/
void	save_std_fds(t_data *data);
void	pipe_out(t_data *d);
void	pipe_in(t_data *d);
void	restore_fds(t_data *data);

/*
** get_binary
*/
char	*test_path(char **cmd, char **paths, char *bin, int i);
char	**get_path(t_data *d);
char	*find_bin(char **paths, char **cmd);
char	**get_absolute_path(char **cmd, t_data *d);

/*
** init
*/

/*
** Built-in
*/

void	ft_env(t_data *d, char **cmd);
void	convert_env(t_data *d);
char	*find_var(char *name);
char	*find_name(char *var);
int		export_var(char **cmd, t_data *d, int j);
int		ft_export(char **cmd, t_data *d);
void	print_export(t_data *d);
t_list	*ft_unset(char **cmd, t_data *d);
void	unset_var(char *var, t_data *d);
int		ft_pwd(void);
int		ft_echo(char **cmd, t_data *d);
int		ft_exit(char **cmd, t_data *d);
int		ft_cd(char **cmd, t_data *d);
/*
** utils
*/
char	*find_var(char *name);
char	*find_name(char *var);

/*
** Free
*/

void	free_stack(t_list *top);
void	free_array(char **array);
void	free_lst(t_list *lst);
void	free_exit(t_data *d, char *error, int exit_code, char *pb);
void	free_all(t_data *d, char **cmd);
void	tests(t_list *env, char **cmd);
void	opening_error(char *error);

/*
** Signals
*/

void	sig_heredoc(int signo);
void	sig_int(int signo);
void	sig_quit(int signo);

#endif
