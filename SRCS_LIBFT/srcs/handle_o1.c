/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_o1.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/07 19:47:33 by tmeulenb       #+#    #+#                */
/*   Updated: 2019/04/08 15:03:25 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_numb_octal_len(unsigned long long numb)
{
	int		count;

	if (numb == 0)
		return (1);
	count = 0;
	while (numb != 0)
	{
		numb = numb / 8;
		count++;
	}
	return (count);
}

void	ft_put_octal(unsigned long long numb, t_print *ptr)
{
	if (numb != 0)
	{
		ft_put_octal(numb / 8, ptr);
		ft_putchar((numb % 8) + 48);
		ptr->g_count += 1;
	}
}

void	ft_check_octal(unsigned long long numb, t_print *ptr)
{
	if (ptr->hash && numb != 0)
	{
		ft_putchar('0');
		ptr->g_count++;
	}
	if (numb != 0)
		ft_put_octal(numb, ptr);
	else if ((numb == 0 && (!ptr->dot || ptr->pc != -1)) || ptr->ozero)
	{
		ft_putchar('0');
		ptr->g_count++;
	}
}
