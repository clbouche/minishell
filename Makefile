########
# NAME #
########

NAME = minishell

###################
# FLAGS & LIBRARY #
###################

#compiler
CC = clang 

#compiler flags
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -lreadline -L
#CFLAGS += -fsanitize=address

###################
# PRINT VARIABLES #
###################

# Reset
NC = \033[0m

# Colors
YELLOW = \033[0;33m
GREEN = \033[32m
BLUE = \033[0;34m
RED = \033[0;31m
PURPLE = \033[0;35m
CYAN = \033[0;36m
BLACK = \033[0;30
WHITE = \033[0;37m

# One Line Output
ONELINE =\e[1A\r

############
# Includes #
############

INCLUDES += -I /includes/minishell.h
INCLUDES += includes/libft/libft.a

########################
# Sources compilations #
########################

PATH_SRCS = srcs
PATH_PARSE = srcs/parsing

SRCS += minishell.c
SRCS += parsing.c

vpath %.c $(PATH_SRCS)
vpath %.c $(PATH_PARSE)

########################
# Objects compilations #
########################

PATH_OBJS = objs/
OBJS = $(patsubst %.c, $(PATH_OBJS)%.o, $(SRCS))

#########
# RULES #
#########

all: $(PATH_OBJS) $(NAME)

$(NAME): $(OBJS) 
		@make -C ./includes/libft
		@$(CC) $(OBJS) $(INCLUDES) $(CFLAGS) 
		@echo "$(GREEN)$@ is ready.\n\n$(NC)"

$(OBJS): $(PATH_OBJS)%.o: %.c Makefile
		@$(CC) -c $< -o $@ 
		@echo "$(ONELINE)$(CYAN)Compiling $<\n$(NC)"

$(PATH_OBJS):
	@mkdir $@

clean:
	@$(RM) $(OBJS)
	@$(RM) -R $(PATH_OBJS)
	@make clean -C ./includes/libft
	@echo "$(PURPLE)Minishell : clean $<"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) includes/libft/libft.a
	@make fclean -C ./includes/libft
	@echo "$(PURPLE)Minishell : fclean"

re: fclean all

.PHONY : all clean fclean re