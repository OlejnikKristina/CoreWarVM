/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_d3.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/07 19:58:45 by tmeulenb       #+#    #+#                */
/*   Updated: 2019/04/08 19:26:14 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				d_just_w_and_zero(t_print *p, long long n)
{
	int		i;
	int		neg;

	i = 0;
	neg = 0;
	if (p->plus && n >= 0)
		ft_putchar('+');
	if (n < 0)
		ft_putchar('-');
	if (p->plus || (n < 0 && !p->plus) || p->sp)
		neg = 1;
	if (p->sp && (p->con == 'd' || p->con == 'i'))
	{
		ft_putchar(' ');
		p->g_count++;
	}
	while (i < p->w - p->nlen - neg)
	{
		ft_putchar('0');
		i++;
		p->g_count++;
	}
	ft_putnbr_long(n, p);
}

void				check_plus(t_print *p, long long n)
{
	if (p->plus && n >= 0)
		ft_putchar('+');
	else if (p->plus)
		ft_putchar('-');
}

void				print_d_extra(t_print *p, int amount, int i, char c)
{
	while (i < amount)
	{
		ft_putchar(c);
		i++;
		p->g_count++;
	}
}
