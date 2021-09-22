#ifndef MINISHELL_H
# define MINISHELL_H

/*
** DEFINE
*/

#define RED "\001\033[31;1m\002"
#define GREEN "\001\e[1;32m\002"
#define RESET "\001\e[0m\002"

/*
** ENUM
*/


typedef enum		e_chr_class {
	CHR_ALPHA,
	CHR_DIGIT,
	CHR_SEMI,
	CHR_DASH,
	CHR_QUOTE, 
	CHR_NL,
	CHR_DOL,
	CHR_PIPE, 
	CHR_REDIR_L, 
	CHR_REDIR_R, 
	CHR_SPACE, 
	CHR_MAX
}					t_chr_class;

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
** STRUCTURES
*/

typedef	struct	s_env
{
	char	*path;
	char	**paths;
}				t_env;

/*typedef	struct s_lst_shell
//typedef	struct	s_list
//{
//		char *data;
//		struct s_env *next;
//}				t_list;

typedef	struct s_lst_shell
{
	void				*cmd;
	char				*arg;
	char				*option;
	struct s_lst_shell	*next;
	t_list				*env;
	int					token;
	char				**path;
	int					output;
	int					input;
}				t_lst_shell;*/

/*
** FUNCTIONS
*/

void	init_env(char **envp, t_list *env);
void	get_env(char **envp, t_list *env);
void	print_env(t_list *env);

/*
** BUILT-IN
*/

void		ft_env(t_list *env);
void		init_path(t_env *path);
void		parser(char *line);
t_dlist		*ft_add_node(t_dlist *lst, char *content);
void		print_dlist(t_dlist *lst);
void		ft_delete_node(t_dlist *list);
t_dlist		*init_list(t_dlist *list);

#endif
