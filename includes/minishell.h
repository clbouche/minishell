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

typedef enum {
	T_WORD,  /* un mot */
	T_BAR,   /* | */
	T_SEMI,  /* ; */
	T_AMPER, /* & */
	T_LT,    /* < */
	T_GT,    /* > */
	T_GTGT,  /* >> */
	T_NL,    /* retour-chariot */
	T_EOF    /* ctrl-d */
} TOKEN;


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
void	get_env(char **envp, t_list *env);
void	print_env(t_list *env);

/*
** BUILT-IN
*/

int	ft_env(t_list *env);
void	ft_export(t_list *env);
void	ft_export_var(t_list *env, char *name, char *variable);
void	ft_unset(t_list *env);
void	ft_unset_arg(t_list *env, char *name);

/*
** FREE
*/
void	free_stack(t_list *top);
#endif
