/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_modulo.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 14:14:56 by tmeulenb       #+#    #+#                */
/*   Updated: 2019/04/08 15:59:23 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero_modulo(t_print *ptr)
{
	int		i;

	i = 0;
	while (i < ptr->w - 1)
	{
		ft_putchar('0');
		ptr->g_count++;
		i++;
	}
}

void	print_modulo(t_print *ptr)
{
	ft_putchar('%');
	ptr->g_count++;
}

void	handle_modulo(t_print *ptr)
{
	int		i;

	i = 0;
	ptr->pc = 0;
	if (ptr->w && !ptr->minus && !ptr->zero)
	{
		fill_space(ptr, ptr->w - 1, 0);
		print_modulo(ptr);
	}
	else if (ptr->w && ptr->minus && !ptr->zero)
	{
		print_modulo(ptr);
		fill_space(ptr, ptr->w - 1, 0);
	}
	else if (ptr->zero)
	{
		zero_modulo(ptr);
		print_modulo(ptr);
	}
	else
		print_modulo(ptr);
	return ;
}
