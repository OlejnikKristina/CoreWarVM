/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_sx.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 18:48:38 by tmeulenb       #+#    #+#                */
/*   Updated: 2019/04/08 17:17:38 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_width_zero(t_print *ptr, unsigned long long n)
{
	if (ptr->hash && n != 0)
		ptr->nlen += 2;
	put_0x(ptr, n);
	fill_zero(ptr->w - ptr->nlen, ptr);
	ft_put_hex(n, ptr);
}

void	print_x(t_print *ptr, unsigned long long n)
{
	int len;

	if (ptr->hash && n != 0)
		ptr->nlen += 2;
	len = ptr->nlen;
	if (ptr->w && ptr->pc && ptr->w > ptr->pc)
		len = ptr->pc + 2;
	if (ptr->w && n == 0 && ptr->pc == -1)
		print_width(ptr);
	else if (ptr->w > len)
		fill_space(ptr, ptr->w - len, 0);
	if (ptr->pc && !ptr->hash)
		fill_zero(ptr->pc - ptr->nlen, ptr);
	ft_put_hex(n, ptr);
}

void	print_x_minus(t_print *ptr, unsigned long long n)
{
	if (ptr->hash && n != 0)
		ptr->nlen += 2;
	if (ptr->pc > ptr->nlen)
		fill_zero(ptr->pc - ptr->nlen, ptr);
	ft_put_hex(n, ptr);
	if (ptr->w)
		fill_space(ptr, ptr->w - ptr->nlen, 0);
}

void	choose_x(t_print *ptr, unsigned long long n)
{
	ptr->nlen = ft_hexlen(n);
	if (ptr->minus)
		print_x_minus(ptr, n);
	else if (ptr->zero && ptr->w)
		print_width_zero(ptr, n);
	else if (!ptr->minus && (ptr->w || ptr->pc))
		print_x(ptr, n);
	else
		ft_put_hex(n, ptr);
}

void	handle_sx(va_list ap, t_print *ptr)
{
	unsigned long long	n;

	n = va_arg(ap, unsigned long long);
	if (ptr->zero && ptr->minus)
		ptr->zero = 0;
	if ((ptr->zero && ptr->pc))
		ptr->zero = 0;
	typecast_u(ptr, &n);
	choose_x(ptr, n);
}
