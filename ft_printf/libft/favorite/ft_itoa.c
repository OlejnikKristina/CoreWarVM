/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 20:58:44 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/12 17:41:53 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoa_half_2(int len, long num_l, char *num)
{
	num[len] = '\0';
	while (num_l > 0)
	{
		len--;
		num[len] = num_l % 10 + '0';
		num_l /= 10;
	}
	return (num);
}

char			*ft_itoa(int n)
{
	int		len;
	long	num_l;
	char	*num;

	num_l = (long)n;
	if (num_l == 0)
		return (ft_strdup("0"));
	len = ft_count_digit(num_l);
	if (num_l < 0)
	{
		num_l = -num_l;
		len++;
		num = ft_strnew(len);
		if (num == NULL)
			return (NULL);
		num[0] = '-';
	}
	else if (
		(num = ft_strnew(len)) == NULL)
		return (NULL);
	return (ft_itoa_half_2(len, num_l, num));
}
