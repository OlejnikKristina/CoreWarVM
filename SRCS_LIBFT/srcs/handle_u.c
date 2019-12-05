/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_u.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/02 15:42:09 by tmeulenb       #+#    #+#                */
/*   Updated: 2019/04/08 13:29:02 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putunsigned_long(unsigned long long n, t_print *ptr)
{
	ptr->g_count++;
	if (n > 9)
	{
		ft_putunsigned_long(n / 10, ptr);
		ft_putchar((n % 10) + 48);
	}
	else
		ft_putchar(n + 48);
}

void		typecast_u(t_print *ptr, unsigned long long *numb)
{
	if (ptr->ll)
		*numb = (unsigned long long)*numb;
	else if (ptr->hh)
		*numb = (unsigned char)*numb;
	else if (ptr->l)
		*numb = (unsigned long)*numb;
	else if (ptr->h)
		*numb = (unsigned short)*numb;
	else if (ptr->z)
		*numb = (size_t)*numb;
	else if (ptr->j)
		*numb = (intmax_t) * numb;
	else
		*numb = (unsigned int)*numb;
}

void		handle_u(va_list ap, t_print *ptr)
{
	unsigned long long		n;

	n = (unsigned long long)va_arg(ap, unsigned long long);
	typecast_u(ptr, &n);
	handle_d(n, ptr);
}
