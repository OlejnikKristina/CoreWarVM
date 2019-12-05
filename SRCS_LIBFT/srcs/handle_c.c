/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_c.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/04 14:43:52 by rvan-ket       #+#    #+#                */
/*   Updated: 2019/04/04 21:28:35 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_c(t_print *ptr, char c)
{
	int		i;

	i = 0;
	if (ptr->minus)
	{
		ft_putchar(c);
		ptr->g_count++;
	}
	while (i < ptr->w - 1)
	{
		if (ptr->zero)
			ft_putchar('0');
		if (!ptr->zero)
			ft_putchar(' ');
		i++;
		ptr->g_count++;
	}
	if (!ptr->minus)
	{
		ft_putchar(c);
		ptr->g_count++;
	}
}

void	go_print_c(va_list ap, t_print *ptr)
{
	char	c;

	c = va_arg(ap, int);
	if (ptr->w)
		ft_width_c(ptr, c);
	if (!ptr->w)
	{
		ft_putchar(c);
		ptr->g_count++;
	}
}
