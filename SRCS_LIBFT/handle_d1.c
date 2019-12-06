/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_d1.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/07 19:54:03 by tmeulenb       #+#    #+#                */
/*   Updated: 2019/04/08 17:47:19 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					check_neg(long long n, t_print *p)
{
	if (n < 0 && (p->con == 'd' || p->con == 'D' || p->con == 'i'))
	{
		p->belowzero = -1;
		return (1);
	}
	else if (p->con == 'p')
		return (2);
	else if (p->plus && n >= 0 && p->zero && !p->pc)
		return (1);
	else if (p->plus && n >= 0)
		return (1);
	else if (p->sp)
		return (1);
	else
		return (0);
}

void				typecast_d(t_print *p, long long *n)
{
	if (p->ll)
		*n = (long long)*n;
	else if (p->hh)
		*n = (signed char)*n;
	else if (p->l)
		*n = (long)*n;
	else if (p->h)
		*n = (short)*n;
	else if (p->z)
		*n = (size_t)*n;
	else if (p->j)
		*n = (intmax_t) * n;
	else
		*n = (int)*n;
}

int					pick_len(t_print *p, long long n, int len, int nlen)
{
	if (!p->pc && !p->w)
		len = nlen;
	else if (!p->w && p->pc)
		len = (p->pc < nlen) ? (nlen) : (p->pc);
	else if (!p->pc && p->w)
		len = (p->w < nlen) ? (nlen) : (p->w);
	else if (p->w < p->pc)
		len = (p->pc > nlen) ? (p->pc) : (nlen);
	else if (p->w > p->pc)
		len = (p->w > nlen) ? (p->w) : (nlen);
	(p->plus && n >= 0) ? len++ : 0;
	if (p->sp && !p->plus)
		len++;
	if (p->pc > p->w || nlen > p->w)
		len++;
	if (n < 0 && p->pc > p->w)
		len++;
	else if (n < 0 && !p->w && !p->pc)
		len++;
	return (len);
}

void				fill_zero(int amount, t_print *p)
{
	int		i;

	i = 0;
	while (i < amount)
	{
		ft_putchar('0');
		p->g_count++;
		i++;
	}
	return ;
}

void				fill_space_extra(t_print *p, long long n)
{
	if (n != 0 && p->hash && (p->con == 'x' ||
	p->con == 'X') && !p->minus && !p->zero)
		ft_putstr("0x");
}
