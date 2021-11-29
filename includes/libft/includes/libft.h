/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:56:59 by clbouche          #+#    #+#             */
/*   Updated: 2021/11/22 11:03:17 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>

# define BUFFER_SIZE 1000000

/*____________________ERROR_________________________*/
# define ERR "Error"
# define ERR_ALLOC "Dynamic allocation problem."
# define ERR_EMPTY_DLIST "Nothing to display, the Dlist is empty"

/*_______________LISTE CHAINEE SIMPLE_________________*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*_______________DOUBLE LISTE CHAINEE_________________*/

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	char			*value;
	int				index;
}					t_node;

typedef struct s_dlist
{
	struct s_node	*begin;
	struct s_node	*end;
	int				len;
}					t_dlist;

/*_______________FONCTIONS_________________*/

/* BASICS */
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	ft_error(char *error);
size_t	ft_intlen(int n);
// void	print_index(t_dlist *stack_a);

/* MANIP  STRING */
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strcpy(char *dest, char *src);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_realloc(char **s1, char *s2);

/* CHECK CHAR */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
bool	ft_iswhitespace(const int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

/* MANIP MEMORY */
void	ft_memdel(char **str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);

/* MANIP FILE */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* MANIP FILE - GNL */
int		get_next_line(int fd, char **line);
int		ft_check(char *str);
char	*ft_form_line(const char *s1);
char	*ft_savetxt(char *s);

/* MANIP LINKED LIST*/
t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstprint(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);

/* MANIP DOUBLE LINKED LIST*/
t_dlist	*ft_dlstnew(char *content);
int		ft_dlstsize(t_dlist *lst);
char	*ft_dlstfirst(t_dlist *lst);
char	*ft_dlstlast(t_dlist *lst);
t_dlist	*ft_dlstadd_back(t_dlist *lst, char *content, int index);
t_dlist	*ft_dlstadd_front(t_dlist *lst, char *content, int index);
void	print_dlist(t_dlist *lst);
void	ft_dlstdelone(t_node *node);
void	ft_dlstdelone_back(t_dlist *lst);
void	ft_dlstdelone_front(t_dlist *lst);
t_dlist	*ft_dlstclear(t_dlist *lst);

#endif
