/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_f1.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/07 19:45:36 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/04/07 19:45:45 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_zero_f(t_print *ptr, int len)
{
	int		i;

	i = 0;
	while (i < ptr->w - len)
	{
		ft_putchar('0');
		ptr->g_count++;
		i++;
	}
}

void		put_space_f(t_print *ptr, int len)
{
	int		i;

	i = 0;
	while (i < ptr->w - len)
	{
		ft_putchar(' ');
		ptr->g_count++;
		i++;
	}
}
