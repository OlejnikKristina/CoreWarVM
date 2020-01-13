/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 20:21:12 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/01 16:01:57 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int			res_i;
	short int	sign;

	sign = 1;
	res_i = 0;
	while (space(*nptr))
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		nptr++;
		sign = -1;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res_i = res_i * 10 + *nptr - '0';
		nptr++;
	}
	return (res_i * sign);
}
