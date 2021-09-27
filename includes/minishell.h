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
#define MAX 4096

/*
** ENUM
*/

typedef enum		e_chr_class {
	CHR_ALPHA,
	CHR_SEP,
	CHR_DIGIT,
	CHR_DASH,
	CHR_QUOTE, 
	CHR_NL,
	CHR_PIPE, 
	CHR_DOL,
	CHR_SEMI,
	CHR_REDIR_L, 
	CHR_REDIR_R, 
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

typedef struct		s_token 
{
	t_token_type	tok_type;
	char			*data;
}					t_token;

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	char			*value;
	int				index;
	t_token_type	token;
}					t_node;

typedef struct s_dlist
{
	struct s_node	*begin;
	struct s_node	*end;
	int				len;
}					t_dlist;

typedef struct s_builtins
{
	char *name;
	int (*func)(void);
}				t_built;
/*
** FUNCTIONS
*/
int		init(char **envp);
t_dlist	*init_list(t_dlist *list);
void	print_dlist(t_dlist *lst);
void	get_env(char **envp);

/*
** Built-in 
*/

int		ft_env();
t_list	*export_var(char **cmd);
int		ft_export(char **cmd);
int		ft_unset(char **cmd);
int		ft_pwd(void);
int		ft_exit();
int		ft_cd(char **cmd);
int		ft_echo(char **cmd);
int	is_builtins(char **cmd);



/*
** Tokenizer
*/ 

void					parser(char *line);
t_dlist					*ft_add_node(t_dlist *lst, t_token *node, int index);
void					print_list(t_dlist *lst);
t_token					split_token(char *input);
t_token					save_token(char *s, int len, t_token_type toktype);
void					ignore_wspace(char *s, int *i);
static t_token_type		get_tok_type[CHR_MAX];
static int				token_chr_rules[T_MAX][CHR_MAX];
static t_chr_class		get_chr_class[255];
static t_chr_class		get_chr_class[255];

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


void tests(t_list *env);

#endif
