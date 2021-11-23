## SOURCES.MK ##

## SRCS ##

SOURCES		+=                            		\
		srcs/minishell.c                     	\


## SRCS/EXECUTION ##

SOURCES		+=                            		\
		srcs/execution/manage_fds.c          	\
		srcs/execution/signals.c             	\
		srcs/execution/get_binary.c          	\
		srcs/execution/exec_simple.c         	\
		srcs/execution/execution.c           	\
		srcs/execution/free.c                	\
		srcs/execution/manage_errors.c       	\


## SRCS/PARSING ##

SOURCES		+=                            		\
		srcs/parsing/variables.c             	\
		srcs/parsing/redir_utils.c           	\
		srcs/parsing/heredoc.c               	\
		srcs/parsing/bool_check_utils.c      	\
		srcs/parsing/parsing.c               	\
		srcs/parsing/set_env.c               	\
		srcs/parsing/redir.c                 	\
		srcs/parsing/split_cmd.c             	\
		srcs/parsing/clean_input.c           	\
		srcs/parsing/init.c                  	\


## SRCS/BUILTINS ##

SOURCES		+=                            		\
		srcs/builtins/is_builtins.c          	\
		srcs/builtins/ft_echo.c              	\
		srcs/builtins/ft_unset.c             	\
		srcs/builtins/ft_exit.c              	\
		srcs/builtins/ft_pwd.c               	\
		srcs/builtins/ft_cd.c                	\
		srcs/builtins/ft_export.c            	\
		srcs/builtins/utils_builtins.c       	\
		srcs/builtins/ft_env.c               	\


