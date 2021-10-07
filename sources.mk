## SOURCES.MK ##

## SRCS ##

SOURCES		+=                           		\
		srcs/minishell.c                    	\


## SRCS/PARSING ##

SOURCES		+=                           		\
		srcs/parsing/init.c                 	\
		srcs/parsing/set_env.c              	\
		srcs/parsing/tokenizer.c            	\
		srcs/parsing/parsing.c              	\
		srcs/parsing/rules_token.c          	\


## SRCS/BUILTINS ##

SOURCES		+=                           		\
		srcs/builtins/ft_export.c           	\
		srcs/builtins/ft_cd.c               	\
		srcs/builtins/ft_exit.c             	\
		srcs/builtins/ft_echo.c             	\
		srcs/builtins/is_builtins.c         	\
		srcs/builtins/ft_unset.c            	\
		srcs/builtins/ft_env.c              	\
		srcs/builtins/ft_pwd.c              	\


## SRCS/EXECUTION ##

SOURCES		+=                           		\
		srcs/execution/get_binary.c         	\
		srcs/execution/manage_errors.c      	\
		srcs/execution/execution.c          	\
		srcs/execution/exec_simple.c        	\
		srcs/execution/free.c               	\


