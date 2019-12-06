/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_d2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/07 19:54:12 by tmeulenb       #+#    #+#                */
/*   Updated: 2019/04/08 18:40:42 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				fill_space(t_print *p, int amount, long long n)
{
	int		i;

	i = 0;
	if (p->w > p->pc && p->nlen < p->pc)
		amount = p->w - p->pc - check_neg(n, p);
	else if (p->w > p->pc && p->nlen > p->pc)
		amount = p->w - p->nlen - check_neg(n, p);
	else if (p->pc > p->nlen)
		amount = p->len - p->pc - check_neg(n, p);
	if (n != 0 && p->hash && (p->con == 'x' || p->con == 'X'))
		i += 2;
	if (p->hash && n != 0 && p->con == 'o' && !p->w)
		amount--;
	if (p->minus && p->w && p->zero)
		p->zero = 0;
	while (i < amount && !p->zero)
	{
		if (!p->zero || (p->zero && (p->w && p->pc)))
			ft_putchar(' ');
		i++;
	}
	fill_space_extra(p, n);
	p->g_count += i;
	return ;
}

void				check_zero(t_print *p)
{
	if (p->zero && p->nlen < p->w)
		fill_zero(p->len - p->nlen, p);
}

void				put_d(t_print *p, long long n)
{
	if (p->sp && !p->plus && n >= 0 && (p->con == 'd' || p->con == 'i'))
		ft_putchar(' ');
	if (p->w > p->nlen && !p->pc)
		fill_space(p, p->w - p->nlen - check_neg(n, p), n);
	if (p->plus && n >= 0 && (p->con == 'd' || p->con == 'i'))
		ft_putchar('+');
	else if (n < 0 && n >= -9223372036854775807)
	{
		if (p->con != 'u')
			ft_putchar('-');
		p->nlen++;
	}
	check_zero(p);
	if (p->pc > p->nlen)
	{
		if (n < 0)
			p->nlen--;
		fill_zero(p->pc - p->nlen, p);
	}
	if (!(((p->dot && p->pc) || p->pc == -1) && n == 0))
		ft_putnbr_long(n, p);
}

void				put_minus_d(t_print *p, long long n)
{
	if ((!p->w && !p->pc) || p->w < p->pc)
		put_d(p, n);
	if (p->w > p->pc)
	{
		if (p->plus && n >= 0 && (p->con == 'd' || p->con == 'i'))
			ft_putchar('+');
		if (n < 0 && (p->con == 'd' || p->con == 'i'))
			ft_putchar('-');
		if (p->sp && n >= 0 && (p->con == 'd' || p->con == 'i'))
			ft_putchar(' ');
		if (p->nlen < p->pc)
			fill_zero(p->pc - p->nlen, p);
		if (!(p->dot && p->pc == -1 && n == 0))
			ft_putnbr_long(n, p);
		if (p->pc > p->nlen)
			p->nlen = p->pc;
		if (p->nlen < p->w)
			fill_space(p, p->w - p->nlen - check_neg(n, p), n);
	}
}

void				increment_gcount(t_print *p, long long n)
{
	if (p->plus && n >= 0 && (p->con == 'd' || p->con == 'i'))
		p->g_count++;
	if (n < 0)
		p->g_count++;
	if (p->sp && !p->plus && n >= 0 &&
	(p->con == 'd' || p->con == 'i') && !p->w)
		p->g_count++;
}
