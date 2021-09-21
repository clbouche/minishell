#ifndef MINISHELL_H
# define MINISHELL_H

/*
** DEFINE
*/

#define RED "\001\033[31;1m\002"
#define GREEN "\001\e[1;32m\002"
#define RESET "\001\e[0m\002"
#define ERROR 1
#define SUCCESS 0

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

//typedef	struct	s_env
//{
//		char *name;
//		char *var;
//		struct s_env *next;
//}				t_env;

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

int		init(char **envp, t_dlist *list);
void	parser(char *line, t_dlist *list);

/*
** ENVIRONNEMENT
*/

void	get_env(char **envp);
void	print_env(t_list **env);
void	free_exit(t_list *lst, char *error);
void	free_lst(t_list *lst);
void	tests(t_list *env);



/*
** BUILT-IN
*/

int		ft_env(t_list *env);
void	ft_export(t_list *env);
void	ft_export_var(t_list *env, char *name, char *variable);
t_list	*ft_unset(t_list *env, char *name);

/*
** FREE
*/
void	free_stack(t_list *top);
t_list	*delete_node(t_list *head, char *var);
t_list	*delete_head(t_list *head);

#endif
