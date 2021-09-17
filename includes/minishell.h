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

typedef enum		e_token
{
	T_CMD, 
	T_ARG, 
	T_OPT, 
	T_WORD,
	T_SIMPLE_REDIR_LEFT, 
	T_SIMPLE_REDIR_RIGHT, 
	T_DOUBLE_REDIR_LEFT,
	T_DOUBLE_REDIR_RIGHT, 
	T_PIPE,
	T_SINGLE_QUOTE, 
	T_DOUBLE_QUOTE, 
	T_BACKSLASH, 
	T_NL, 
	T_EOF,
	T_MAX
}					t_token;

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

static t_token		g_get_tok_type[CHR_MAX] = {
	[CHR_ALPHA] = T_WORD,
	[CHR_DASH] = T_OPT,
	[CHR_DIGIT] = T_WORD,
};

static t_chr_class		g_get_chr_class[255] =
{
	['A'...'Z'] = CHR_ALPHA,
	['a'...'z'] = CHR_ALPHA,
	['-'] = CHR_DASH,
	['"'] = CHR_QUOTE,
	[' '] = CHR_SPACE,
	['$'] = CHR_DOL,
	['0'...'9'] = CHR_DIGIT,
};
//[''] = CHR_SEMI,
//j'ai enleve le ; ligne 65 qui faisait des trucs chelous
static int				g_token_chr_rules[T_MAX][CHR_MAX] =
{
	[T_CMD] = {
		[CHR_ALPHA] = 1,
	},
	[T_OPT] = {
		[CHR_DASH] = 1,
		[CHR_ALPHA] = 1,
		[CHR_DIGIT] = 1,
		[CHR_QUOTE] = 0,
	},
	[T_ARG] = {
		[CHR_ALPHA] = 1,
		[CHR_QUOTE] = 1,
	},
};


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

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	char			*value;
	t_token			type;
}					t_node;

typedef struct s_dlist
{
	struct s_node	*begin;
	struct s_node	*end;
	int				len;
}					t_dlist;

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
}				t_lst_shell;



/*
** FUNCTIONS
*/

int		init(char **envp, t_list *env, t_dlist *list);
void	parser(char *line, t_dlist *list);
void	init_env(char **envp, t_list *env);
void	get_env(char **envp, t_list *env);
void	print_env(t_list *env);

/*
** BUILT-IN
*/

<<<<<<< HEAD
void		ft_env(t_list *env);
void		init(t_env *env);
void		parser(char *line);
t_dlist		*ft_add_node(t_dlist *lst, char *content);
void		print_dlist(t_dlist *lst);
void		ft_delete_node(t_dlist *list);
t_dlist		*init_list(t_dlist *list);

=======
int	ft_env(t_list *env);
void	ft_export(t_list *env);
void	ft_export_var(t_list *env, char *name, char *variable);
void	ft_unset(t_list *env);
void	ft_unset_arg(t_list *env, char *name);
>>>>>>> lulu

/*
** FREE
*/
void	free_stack(t_list *top);
#endif
