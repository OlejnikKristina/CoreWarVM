/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_f.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 15:03:01 by tmeulenb       #+#    #+#                */
/*   Updated: 2019/04/04 21:33:18 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		f_width(t_print *ptr, char *str)
{
	if (ptr->sp || (ptr->plus && str[0] != '-'))
		ptr->w--;
	if ((ptr->sp || (ptr->plus && str[0] != '-')) && ptr->zero)
	{
		ptr->sp ? ft_putchar(' ') : ft_putchar('+');
		ptr->g_count++;
	}
	if (str[0] == '-' && ptr->zero)
		ft_putchar('-');
	if (!ptr->zero)
		put_space_f(ptr, ptr->nlen);
	else if (ptr->zero)
		put_zero_f(ptr, ptr->nlen);
	if ((ptr->sp || (ptr->plus && str[0] != '-')) && !ptr->zero)
	{
		ptr->sp ? ft_putchar(' ') : ft_putchar('+');
		ptr->g_count++;
	}
	if (ptr->zero && str[0] == '-')
		ft_putstr(str + 1);
	else
		ft_putstr(str);
	return ;
}

void		f_minus(t_print *ptr, char *str)
{
	if (ptr->sp || ptr->plus)
		ptr->w--;
	if (ptr->sp || ptr->plus)
	{
		ptr->sp ? ft_putchar(' ') : ft_putchar('+');
		ptr->g_count++;
	}
	ft_putstr(str);
	put_space_f(ptr, ptr->nlen);
}

void		print_f(t_print *ptr, char *fstr)
{
	ptr->nlen = ft_strlen(fstr);
	ptr->g_count += ft_strlen(fstr);
	if (!ptr->minus)
		f_width(ptr, fstr);
	else if (ptr->minus)
		f_minus(ptr, fstr);
	return ;
}

void		handle_f(long double numb, t_print *ptr)
{
	char		*fstr;

	if (ptr->plus && ptr->sp)
		ptr->sp = 0;
	if (ptr->zero && ptr->minus)
		ptr->zero = 0;
	if (!ptr->pc)
		ptr->pc = 6;
	else if (ptr->pc == -1)
		ptr->pc = 0;
	fstr = f_string(numb, ptr);
	roundup_f_string(fstr, ptr);
	final_fstring(fstr, ptr);
	print_f(ptr, fstr);
}

void		get_arg_f(va_list ap, t_print *ptr)
{
	if (ptr->big_l)
	{
		ptr->cap_l = (long double)va_arg(ap, long double);
		handle_f(ptr->cap_l, ptr);
	}
	else
	{
		ptr->no_cap_l = (double)va_arg(ap, double);
		handle_f(ptr->no_cap_l, ptr);
	}
}
