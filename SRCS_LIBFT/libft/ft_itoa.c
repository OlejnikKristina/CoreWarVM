/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rvan-ket <rvan-ket@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:28:56 by awehlbur       #+#    #+#                */
/*   Updated: 2019/07/11 17:13:49 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int		ft_calc(long long int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(long long int n)
{
	char	*str;
	size_t	i;

	i = ft_calc(n) + 1;
	str = (char*)malloc(sizeof(char) * i);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[i - 1] = '\0';
	while (n)
	{
		i--;
		str[i - 1] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
