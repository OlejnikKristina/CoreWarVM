/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_nan_inf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/07/19 20:32:01 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

short int	is_nan_inf(long double value, char **float_str)
{
	if (value == (1.0 / 0.0))
		(*float_str) = ft_strdup("inf");
	else if (value == (-1.0 / 0.0))
		(*float_str) = ft_strdup("-inf");
	else if (value != value)
		(*float_str) = ft_strdup("nan");
	else
		return (0);
	return (1);
}
