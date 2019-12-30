/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_o.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 18:47:17 by tmeulenb       #+#    #+#                */
/*   Updated: 2019/04/08 19:22:31 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_width(t_print *ptr)
{
	int		i;

	i = 0;
	while (i < ptr->w)
	{
		ft_putchar(' ');
		i++;
		ptr->g_count++;
	}
	return ;
}

void	fill_o(t_print *ptr, int amount, char c)
{
	int		i;

	i = 0;
	while (i < amount)
	{
		ft_putchar(c);
		i++;
		ptr->g_count++;
	}
}

void	print_o_withoutminus(t_print *ptr, unsigned long long n)
{
	if (n == 0 && ptr->pc && ptr->pc != -1 && ptr->w)
		ptr->nlen++;
	if (ptr->w && !ptr->pc)
	{
		if (ptr->zero)
			fill_o(ptr, ptr->w - ptr->nlen - ptr->hash, '0');
		else if (!ptr->zero)
			fill_o(ptr, ptr->w - ptr->nlen - ptr->hash, ' ');
	}
	else if (ptr->pc && (!ptr->w || ptr->w < ptr->pc))
		fill_o(ptr, ptr->pc - ptr->nlen - ptr->hash, '0');
	else if (ptr->w && ptr->pc)
	{
		if (ptr->w > ptr->pc && ptr->pc > ptr->nlen)
		{
			fill_o(ptr, ptr->w - ptr->pc, ' ');
			fill_o(ptr, ptr->pc - ptr->nlen - ptr->hash, '0');
		}
		else if (ptr->w > ptr->pc && ptr->pc <= ptr->nlen)
			fill_o(ptr, ptr->w - ptr->nlen - ptr->hash, ' ');
	}
	ft_check_octal(n, ptr);
}

void	print_o_withminus(t_print *ptr, unsigned long long n)
{
	if (n == 0 && ptr->pc && ptr->w)
		ptr->nlen++;
	if (ptr->pc)
		fill_o(ptr, ptr->pc - ptr->nlen - ptr->hash, '0');
	ft_check_octal(n, ptr);
	if (ptr->w && ptr->w > ptr->pc)
	{
		if (ptr->pc > ptr->nlen)
			fill_o(ptr, ptr->w - ptr->pc - ptr->hash, ' ');
		else if (ptr->pc < ptr->nlen)
			fill_o(ptr, ptr->w - ptr->nlen - ptr->hash, ' ');
	}
	return ;
}

void	handle_o(va_list ap, t_print *ptr)
{
	unsigned long long	n;

	n = va_arg(ap, unsigned long long);
	typecast_u(ptr, &n);
	ptr->nlen = ft_numb_octal_len(n);
	if (n == 0 && ptr->hash)
	{
		ptr->hash = 0;
		ptr->ozero = 1;
	}
	if (n == 0 && ptr->w && (ptr->dot || ptr->pc == -1))
		ptr->nlen--;
	if (!ptr->minus)
		print_o_withoutminus(ptr, n);
	else if (ptr->minus)
		print_o_withminus(ptr, n);
	return ;
}
