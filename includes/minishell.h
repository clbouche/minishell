#ifndef MINISHELL_H
# define MINISHELL_H

/*
** DEFINE
*/




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

/*typedef	struct s_lst_shell
{
	void				*cmd;
	char				*arg;
	char				*option;
	struct s_lst_shell	*next;
	int					token;
	char				**path;
	int					output;
	int					input;
}				t_lst_shell;*/


typedef	struct	s_env
{
	char	*path;
	char	**paths;
}				t_env;


/*
** FUNCTIONS
*/

int		init(t_env *env, t_dlist *list);
void	parser(char *line, t_dlist *list);

#endif
