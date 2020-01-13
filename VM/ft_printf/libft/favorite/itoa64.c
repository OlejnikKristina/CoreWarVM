/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   itoa64.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/08 18:06:13 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/22 12:32:41 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

unsigned	count_digit64(int64_t nbr)
{
	unsigned amount;

	amount = 0;
	if (nbr <= 0)
	{
		nbr *= (-1);
		amount++;
	}
	while (nbr)
	{
		nbr /= 10;
		amount++;
	}
	return (amount);
}

char		*itoa64(int64_t nbr)
{
	short	digit_amount;
	bool	sign;
	char	*str;

	sign = 0;
	digit_amount = count_digit64(nbr);
	if (nbr == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	str = (char *)malloc(digit_amount + 1);
	str[digit_amount] = '\0';
	digit_amount--;
	if (nbr < 0)
	{
		sign = 1;
		nbr = -nbr;
	}
	while (0 <= digit_amount)
	{
		str[digit_amount] = nbr % 10 + '0';
		nbr /= 10;
		--digit_amount;
	}
	(sign) ? str[0] = '-' : 1;
	return (str);
}

char		*pf_itoa_ll(long long nbr)
{
	short	digit_amount;
	bool	sign;
	char	*str;

	sign = 0;
	digit_amount = count_digit64(nbr);
	str = (char *)malloc(digit_amount + 1);
	str[digit_amount] = '\0';
	digit_amount--;
	if (nbr < 0)
	{
		sign = 1;
		nbr = -nbr;
	}
	while (0 <= digit_amount)
	{
		str[digit_amount] = nbr % 10 + '0';
		nbr /= 10;
		--digit_amount;
	}
	(sign) ? str[0] = '-' : 1;
	return (str);
}

unsigned	count_digit64u(uint64_t nbr)
{
	unsigned amount;

	amount = 0;
	if (nbr <= 0)
	{
		nbr *= (-1);
		amount++;
	}
	while (nbr)
	{
		nbr /= 10;
		amount++;
	}
	return (amount);
}

char		*itoa64u(uint64_t nbr)
{
	int32_t	digit_amount;
	char	*str;

	digit_amount = count_digit64u(nbr);
	str = (char *)malloc(digit_amount + 1);
	str[digit_amount] = '\0';
	digit_amount--;
	while (0 <= digit_amount)
	{
		str[digit_amount] = nbr % 10 + '0';
		nbr /= 10;
		--digit_amount;
	}
	return (str);
}
