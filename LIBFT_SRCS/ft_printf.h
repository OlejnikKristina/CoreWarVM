/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/21 19:52:23 by awehlbur       #+#    #+#                */
/*   Updated: 2019/07/09 16:04:50 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include "get_next_line.h"
# include <stdarg.h>

# define FLAGCHECK(x) (x == '+' || x == '-' || x == ' ' || x == '0' || x == '#')
# define CHECKBASE(x) (x == 'o' || x == 'O' || x == 'x' || x == 'X')
# define CHECKF(x) (x == 'f' || x == 'F')

typedef struct		s_print
{
	int				w;
	int				pc;
	char			con;
	int				l;
	int				ll;
	int				h;
	int				big_l;
	int				hh;
	int				dot;
	int				hash;
	int				plus;
	int				zero;
	int				minus;
	int				sp;
	int				lenf;
	int				g_count;
	int				len;
	int				nlen;
	int				belowzero;
	int				z;
	int				j;
	int				i;
	int				ozero;
	int				npc;
	long double		cap_l;
	double			no_cap_l;
}					t_print;

char				*ft_itoa_base(unsigned long long value, int base);
char				*f_string(long double numb, t_print *ptr);
char				*roundup(char *fstr, t_print *ptr, int i);
char				*roundup_f_string(char *fstr, t_print *ptr);
int					ft_printf(char const *format, ...);
int					ft_nlen(long long nb);
int					checkchar(char x);
int					checkint(char x);
int					ft_numblen_unsinged(unsigned long long nb);
int					pick_len(t_print *p, long long n, int len, int nlen);
int					check_neg(long long n, t_print *p);
int					ft_numb_octal_len(unsigned long long numb);
int					ft_hexlen(unsigned long long nb);
int					len_s(t_print *ptr, char *s);
int					get_len_s(t_print *ptr, char *s);
t_print				*ft_newlist(void);
void				ft_check_width(const char *format, int i, t_print *ptr);
void				ft_check_precision(const char *format, int i, t_print *ptr);
void				ft_check_modifier(const char *format, int i, t_print *ptr);
void				ft_afterdot(long double numb, t_print *ptr, \
char *fstr, int i);
void				final_fstring(char *fstr, t_print *ptr);
void				ft_putunsigned_long(unsigned long long n, t_print *ptr);
void				typecast_u(t_print *ptr, unsigned long long *numb);
void				handle_u(va_list ap, t_print *ptr);
void				print_width_zero(t_print *ptr, unsigned long long n);
void				print_x(t_print *ptr, unsigned long long n);
void				print_x_minus(t_print *ptr, unsigned long long n);
void				choose_x(t_print *ptr, unsigned long long n);
void				handle_sx(va_list ap, t_print *ptr);
void				space_s(t_print *ptr, int amount);
void				put_s_minus(t_print *ptr, char *s);
void				put_s(t_print *ptr, char *s, int i);
void				put_null_s_minus(t_print *ptr, \
char *nullstring);
void				put_null_s(t_print *ptr);
void				handle_s(va_list ap, t_print *ptr);
void				p_fill_zero(t_print *ptr, int amount);
void				p_fill_space(t_print *ptr, int amount);
void				put_0x(t_print *ptr, unsigned long long n);
void				print_p(t_print *ptr, unsigned long long n);
void				ft_print_h(char *hexstr, t_print *ptr);
void				ft_put_hex(unsigned long long n, t_print *ptr);
void				handle_p(va_list ap, t_print *ptr);
void				put_zero(t_print *ptr);
void				ft_put_octal(unsigned long long numb, t_print *ptr);
void				ft_check_octal(unsigned long long numb, t_print *ptr);
void				print_minus_o(t_print *ptr, unsigned long long n);
void				print_width(t_print *ptr);
void				print_o(t_print *ptr, unsigned long long n);
void				handle_o(va_list ap, t_print *ptr);
void				zero_modulo(t_print *ptr);
void				print_modulo(t_print *ptr);
void				handle_modulo(t_print *ptr);
void				put_zero_f(t_print *ptr, int len);
void				put_space_f(t_print *ptr, int len);
void				f_width(t_print *ptr, char *str);
void				f_minus(t_print *ptr, char *str);
void				print_f(t_print *ptr, char *fstr);
void				handle_f(long double numb, t_print *ptr);
void				get_arg_f(va_list ap, t_print *ptr);
void				d_just_w_and_zero(t_print *p, long long n);
void				check_plus(t_print *p, long long n);
void				fill_space(t_print *p, int amount, long long n);
void				check_zero(t_print *p);
void				put_d(t_print *p, long long n);
void				put_minus_d(t_print *p, long long n);
void				increment_gcount(t_print *p, long long n);
void				typecast_d(t_print *p, long long *n);
void				fill_zero(int amount, t_print *p);
void				fill_space_extra(t_print *p, long long n);
void				check_minus(long long n);
void				print_d_with_prec(t_print *p, long long n);
void				print_d(t_print *p, long long n);
void				get_arg_d(va_list ap, t_print *p);
void				handle_d(long long n, t_print *p);
void				ft_width_c(t_print *ptr, char c);
void				go_print_c(va_list ap, t_print *ptr);
void				ft_check_int_conversion(const char *format, \
int i, t_print *ptr);
void				ft_check_char_conversion(const char *format, \
int i, t_print *ptr);
void				ft_check_int_base_conversions(const char *format, \
int i, t_print *ptr);
void				ft_check_f_conversion(const char *format, \
int i, t_print *ptr);
void				ft_check_conversion(const char *format, \
int i, t_print *ptr);
void				*ft_check_flag(const char *format, \
int i, t_print *ptr);
void				go_printf(va_list ap, t_print *ptr);
void				ft_check_arg(const char *format, int i, t_print *ptr);
void				ft_printf_loop(char const *format, \
va_list ap, t_print *ptr);
void				ft_flags_to_zero(t_print *flag);
void				ft_putnbr_long(long long n, t_print *ptr);
void				ft_putdot(char *fstr, t_print *ptr);
void				print_d_extra(t_print *p, int amount, int i, char c);

#endif
