/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_p1.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/07 19:51:39 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/04/07 19:51:41 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_fill_zero(t_print *ptr, int amount)
{
	int		i;

	i = 0;
	while (i < amount)
	{
		ft_putchar('0');
		i++;
		ptr->g_count++;
	}
	return ;
}

void	p_fill_space(t_print *ptr, int amount)
{
	int		i;

	i = 0;
	while (i < amount)
	{
		ft_putchar(' ');
		i++;
		ptr->g_count++;
	}
	return ;
}

int		ft_hexlen(unsigned long long nb)
{
	int		count;

	if (nb == 0)
		return (1);
	count = 0;
	while (nb != 0)
	{
		nb = nb / 16;
		count++;
	}
	return (count);
}

void	put_0x(t_print *ptr, unsigned long long n)
{
	if (ptr->hash && ptr->con == 'X' && n != 0)
	{
		ft_putstr("0X");
		ptr->g_count += 2;
	}
	else if (ptr->con == 'p' || ptr->con == 'P')
	{
		ft_putstr("0x");
		ptr->g_count += 2;
	}
	else if (ptr->hash && ptr->con == 'x' && n != 0)
	{
		ft_putstr("0x");
		ptr->g_count += 2;
	}
}
