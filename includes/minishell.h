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

typedef enum		e_chr_class {
	CHR_ALPHA,
	CHR_SEP,
	CHR_DIGIT,
	CHR_DASH,
	CHR_SIMPLE_QUOTE, 
	CHR_DOUBLE_QUOTE,
	CHR_NL,
	CHR_PIPE, 
	CHR_REDIR_L, 
	CHR_REDIR_R, 
	// CHR_DOL,
	// CHR_SEMI,
	CHR_MAX
}					t_chr_class;

/*
** STRUCTURES
*/


typedef	struct s_data
{
	t_list	*env;
	int		fd_in;
	int		fd_out;
	int 	ret;
}				t_data;


typedef struct		s_token 
{
	t_token_type	tok_type;
	char			*data;
}					t_token;

/*
** FUNCTIONS
*/
t_list	*init(t_data *data, char **envp);
t_list *get_env(t_list *env, char **envp);

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
** Tokenizer
*/ 

void			parser(char *line, t_data *data);
t_token_type	get_tok_type[CHR_MAX];
int				token_chr_rules[T_MAX][CHR_MAX];
t_chr_class		get_chr_class[255];
t_token			split_token(char *input);
void			ignore_wspace(char *s, int *i);
t_token			save_token(char *s, int len, t_token_type toktype);

/*
** Parsing
*/

void	free_stack(t_list *top);
t_list	*delete_node(t_list *head, char *var);
t_list	*delete_head(t_list *head);

/*
** FREE
*/

void	free_stack(t_list *top);
t_list	*delete_node(t_list *head, char *var);
t_list	*delete_head(t_list *head);
void	free_lst(t_list *lst);
void	free_exit(t_list *lst, char *error);

void	get_path(char **cmd, char **envp);
void	tests(t_list *env, char **cmd);

#endif
