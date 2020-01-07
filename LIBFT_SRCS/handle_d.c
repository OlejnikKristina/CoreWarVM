/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_d.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 19:20:03 by tmeulenb       #+#    #+#                */
/*   Updated: 2019/04/08 19:48:32 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				check_minus(long long n)
{
	if (n < 0)
		ft_putchar('-');
}

void				print_d_with_prec(t_print *p, long long n)
{
	int		i;
	int		plus;

	plus = 0;
	if (p->plus)
		plus = 1;
	i = 0;
	if (p->nlen > p->pc)
		p->pc = p->nlen;
	if (p->sp && (p->npc == 1 || (p->dot && !p->pc)))
		ft_putchar(' ');
	print_d_extra(p, p->w - p->pc - plus, 0, ' ');
	check_plus(p, n);
	i = 0;
	print_d_extra(p, p->pc - p->nlen, 0, '0');
	if (!(((p->dot && p->pc) || p->pc == -1) && n == 0))
		ft_putnbr_long(n, p);
	else if (n == 0 && p->zero && p->w && p->plus)
		ft_putchar('0');
	return ;
}

void				print_d(t_print *p, long long n)
{
	if (((!p->w && !p->pc) || (p->w < p->pc)) && !p->minus)
		put_d(p, n);
	else if (p->w && n == 0 && p->pc == -1)
		print_width(p);
	else if (p->w > p->pc && p->pc && (p->plus || p->sp) && !p->minus)
		print_d_with_prec(p, n);
	else if (p->w && p->zero && !p->pc)
		d_just_w_and_zero(p, n);
	else if (p->w > p->pc && !p->minus)
	{
		if (p->zero && p->w && p->pc)
		{
			p->zero = 0;
			fill_space(p, p->w - p->pc, n);
			check_minus(n);
			fill_zero(p->pc - p->nlen, p);
			ft_putnbr_long(n, p);
			return ;
		}
		if (p->nlen < p->w && p->pc)
			fill_space(p, p->len - p->nlen - check_neg(n, p), n);
		put_d(p, n);
	}
	else if (p->minus)
		put_minus_d(p, n);
}

void				get_arg_d(va_list ap, t_print *p)
{
	long long		n;

	n = (long long)va_arg(ap, long long);
	typecast_d(p, &n);
	increment_gcount(p, n);
	handle_d(n, p);
}

void				handle_d(long long n, t_print *p)
{
	if (p->zero && p->minus)
		p->zero = 0;
	p->len = pick_len(p, n, 0, ft_nlen(n));
	if (p->con == 'd' || p->con == 'i')
		p->nlen = ft_nlen(n);
	else
		p->nlen = ft_numblen_unsinged((unsigned long long)n);
	if (!(p->dot && p->pc == -1 && n == 0) && p->con != 'u')
		p->g_count += p->nlen;
	print_d(p, n);
}
