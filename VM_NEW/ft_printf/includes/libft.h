/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 17:36:16 by krioliin       #+#    #+#                */
/*   Updated: 2019/12/27 17:46:45 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int						get_next_line(const int fd, char **line);
size_t					ft_strlen(const char *s1);
size_t					ft_strlcat(char *dst, const char *src, size_t dstsize);
char					*ft_strdup(const char *str);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strncpy(char *dest, const char *src, size_t count);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *str1, const char *str2,
						size_t n);
char					*ft_strcat(char *dest, const char *src);
char					*ft_strncat(char *dest, const char *src, size_t n);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_isdigit(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
int						ft_atoi(const char *nptr);
void					ft_bzero(void *s, size_t n);
void					*ft_memset(void *s, int c, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memccpy(void *dest, const void *src, int c,
						size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
/*
** ********************** Second part ********************************
*/
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					ft_memdel(void **ap);
void					*ft_memalloc(size_t size);
char					*ft_strnew(size_t size);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *str, int c);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
void					ft_strclr(char *s);
void					ft_strdel(char **as);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
						char (*f)(unsigned int, char));
char					*ft_strsub(char const *s, unsigned int start,
						size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
int						ft_strequ(char const *s1, char const *s2);
void					ft_putstr(char const *str);
void					ft_putnbr(int n);
void					ft_putchar(char c);
void					ft_putchar_fd(char c, int fd);
short					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_putendl(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_itoa(int n);

/*
** ************************ Private ******************************** **
*/

char					*ft_superjoin(char **s1, const char *s2);
int						space(char c);
int						ft_count_digit(long num);
int						findchr(const char *s, int c);
int						kr_count_words(char const *s, char c);
int						ft_recursive_factorial(int nb);
int						ft_sqrt(int nb);
void					ft_foreach(int *tab, int length, void (*f)(int));
char					*ft_strrev(char str_rev[]);
int						*ft_range(int min, int max);

/*
** *********************** Itoas ********************************** **
*/

char					*itoa64u(uint64_t nbr);
char					*itoa64(int64_t nbr);
char					*itoa_base64u(uint64_t value, short base,
						bool uppercase);
char					*itoa_base64(int64_t value, short base, bool uppercase);
void					ft_ftoa(long double num, char **float_str,
						unsigned precision, long double multiply_me);
char					*pf_itoa_ll(long long nbr);
unsigned				count_digit64u(uint64_t nbr);
unsigned				count_digit64(int64_t nbr);
#endif
