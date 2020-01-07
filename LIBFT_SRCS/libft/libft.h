/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 21:46:10 by awehlbur       #+#    #+#                */
/*   Updated: 2019/12/10 14:42:13 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <unistd.h>
# include "../get_next_line.h"
# include "../ft_printf.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				*ft_strndup(const char *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
size_t				ft_strlen(const char *s);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strdup(const char *str);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, \
								const char *needle, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
long long			ft_atoi(const char *s1);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_putendl_fd(char const *c, int fd);
void				ft_putnbr_fd(int c, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *c, int fd);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				**ft_strsplit(char const *s, char c);
void				ft_strclr(char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(long long int n);
int					ft_count_words(const char *s, char c);
char				*ft_str_tolower(char *s);
char				*ft_str_toupper(char *s);
unsigned long		ft_putwchar2(unsigned int c, char *letter);
unsigned long		ft_putwchar(unsigned int c);
t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_print_int_array(int *array, int arr_size);
void				ft_list_add_back(t_list **alst, t_list *new);
char				*ft_strjoinone(char *s, char c);
int					str_is_digit(char *str);
void				ft_lstrev(t_list **list);
char				**ft_strsplit_ws(char const *s);
#endif
