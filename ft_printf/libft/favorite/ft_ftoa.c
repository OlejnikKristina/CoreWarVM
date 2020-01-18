/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ftoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/26 20:03:50 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		add_zeros(unsigned dig_amount, char **result, ssize_t width)
{
	int			extra_zeros;
	char		*zeros_str;

	if (width < dig_amount)
		return ;
	extra_zeros = width - dig_amount;
	zeros_str = ft_strnew(extra_zeros);
	ft_memset(zeros_str, '0', extra_zeros);
	*result = ft_superjoin(result, zeros_str);
	ft_strdel(&zeros_str);
	return ;
}

static short	f_rounding(char **float_str, int len)
{
	short	nine;

	nine = 0;
	if ((*float_str)[len] <= '5' || !len || (*float_str)[len] == '.')
	{
		if ((*float_str)[len] == '.')
			return ((*float_str)[len + 1] == '9');
		if ((*float_str)[len] != '.')
			(*float_str)[len] += 1;
		return (0);
	}
	if ('5' < (*float_str)[len])
		nine = f_rounding(float_str, len - 1);
	if ('9' == (*float_str)[len] && !nine)
		(*float_str)[len] = '0';
	else if (!nine)
		(*float_str)[len] = (*float_str)[len] + 1;
	return (0);
}

static void		f_add_exponent(char **exponent_str,
char **float_str, unsigned precision)
{
	*float_str = ft_superjoin(float_str, ".");
	if (*exponent_str[0] == '0')
		add_zeros(0, exponent_str, precision);
	*float_str = ft_superjoin(float_str, *exponent_str);
	f_rounding(float_str, ft_strlen(*float_str) - 1);
	ft_strdel(exponent_str);
}

void			ft_ftoa(long double num, char **float_str, unsigned precision,
long double multiply_me)
{
	unsigned long long	exponent;
	unsigned			i;
	long long			value;
	char				*exponent_str;

	i = 0;
	value = (long long)num;
	if (num == 0.0 && (1 / num < 0))
		*float_str = ft_strdup("-0");
	else
		*float_str = itoa64(value);
	(value < 0) ? value *= -1 : 1;
	(num < 0) ? num *= -1 : 1;
	if (precision)
	{
		while (i < precision)
		{
			multiply_me *= 10;
			i++;
		}
		exponent = (num - value) * multiply_me;
		exponent_str = itoa64u(exponent);
		f_add_exponent(&exponent_str, float_str, precision);
		(*float_str)[ft_strlen(*float_str) - 1] = '\0';
	}
}
