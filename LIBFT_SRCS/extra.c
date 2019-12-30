/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extra.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 13:28:51 by awehlbur       #+#    #+#                */
/*   Updated: 2019/04/08 19:40:05 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_to_zero(t_print *flag)
{
	flag->w = 0;
	flag->pc = 0;
	flag->l = 0;
	flag->ll = 0;
	flag->h = 0;
	flag->big_l = 0;
	flag->hh = 0;
	flag->dot = 0;
	flag->hash = 0;
	flag->plus = 0;
	flag->zero = 0;
	flag->minus = 0;
	flag->sp = 0;
	flag->lenf = 0;
	flag->len = 0;
	flag->nlen = 0;
	flag->belowzero = 0;
	flag->z = 0;
	flag->j = 0;
	flag->i = 0;
	flag->no_cap_l = 0;
	flag->cap_l = 0;
	flag->ozero = 0;
	flag->npc = 0;
}

int		ft_nlen(long long nb)
{
	int			i;
	long long	x;

	x = -9223372036854775807;
	if (nb == 0)
		return (1);
	i = 0;
	if (nb == x)
		return (19);
	nb < 0 ? nb = -nb : 0;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int		ft_numblen_unsinged(unsigned long long nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_long(long long n, t_print *ptr)
{
	if (!((((ptr->dot && (ptr->pc == -1 || ptr->pc == 0))) && n == 0)))
	{
		if ((ptr->ll || ptr->j || ptr->z || ptr->l) && n < -9223372036854775807)
		{
			ft_putstr("-9223372036854775808");
			ptr->g_count += 19;
			return ;
		}
		if (ptr->con == 'u')
		{
			ft_putunsigned_long(n, ptr);
			return ;
		}
		n < 0 ? n = -n : 0;
		if (n > 9)
		{
			ft_putnbr_long(n / 10, ptr);
			ft_putchar((n % 10) + 48);
		}
		else
			ft_putchar(n + 48);
	}
}

void	ft_putdot(char *fstr, t_print *ptr)
{
	int		i;

	i = 0;
	while (fstr[i])
		i++;
	if (!ptr->hash && ptr->pc != 0)
		fstr[i] = '.';
}
