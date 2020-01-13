/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_precision.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/02 12:36:11 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/27 20:47:16 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_precision(t_format_spec *spec, t_placeholder *result)
{
	if (!spec->precision || spec->precision == -42)
		return ;
	if (spec->is_negative)
		spec->precision += 1;
	add_zeros(spec->dig_amount, &result->str, spec->precision);
}
