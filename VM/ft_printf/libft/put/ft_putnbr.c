/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 20:21:12 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/01 18:08:19 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int		res;
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	res = nbr % 10 + '0';
	if ((nbr / 10) != 0)
		ft_putnbr(nbr / 10);
	write(1, &res, 1);
}
