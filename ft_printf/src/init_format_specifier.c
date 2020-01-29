/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_format_specifier.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 00:12:30 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/27 20:51:44 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	check_flags(char **input, t_format_spec *specifier)
{
	while (ft_strchr("-+ 0#", **input))
	{
		if (**input == '-')
			(specifier->flag_minus = true);
		if (**input == '+')
			(specifier->flag_plus = true);
		if (**input == ' ')
			(specifier->flag_space = true);
		if (**input == '0')
			(specifier->flag_zero = true);
		if (**input == '#')
			(specifier->flag_hash = true);
		(*input)++;
	}
	return (true);
}

bool	check_precision(char **input, t_format_spec *specifier, va_list arg_ptr)
{
	specifier->precision = 0;
	if ((*input)[0] == '.')
		(*input)++;
	else
		return (false);
	if (**input == '*')
	{
		specifier->precision = -4242;
		(*input)++;
	}
	else if (ft_isdigit(**input))
	{
		specifier->precision = ft_atoi(*input);
		(*input) += ft_count_digit(specifier->precision);
	}
	return (true);
}

bool	check_width_filed(char **input, t_format_spec *format_specifier,
va_list arg_ptr)
{
	format_specifier->width = 0;
	if (**input == '*')
	{
		format_specifier->width = (int)va_arg(arg_ptr, int);
		if (format_specifier->width < 0)
		{
			format_specifier->width *= -1;
			format_specifier->flag_minus = true;
		}
		(*input)++;
	}
	else if (ft_isdigit(**input))
	{
		format_specifier->width = ft_atoi(*input);
		(*input) += ft_count_digit(format_specifier->width);
	}
	return (format_specifier->width);
}

bool	check_length_filed(char **input, t_format_spec *format_specifier)
{
	if (**input == 'h' && (*input)[1] == 'h')
		format_specifier->len_hh = true;
	else if (**input == 'h')
		format_specifier->len_h = true;
	else if (**input == 'l' && (*input)[1] == 'l')
		format_specifier->len_ll = true;
	else if (**input == 'l')
		format_specifier->len_l = true;
	else if (**input == 'L')
		format_specifier->len_lupper = true;
	else
		return (false);
	if (format_specifier->len_hh || format_specifier->len_ll)
		(*input)++;
	(*input)++;
	return (true);
}

bool	check_type(char **input, t_format_spec *specifier, bool no_dot)
{
	if (ft_strchr("%cspdiouxXfCS{", **input))
	{
		specifier->type = **input;
		(*input)++;
		if (specifier->type == 'C')
			specifier->type = 'c';
		if (specifier->type == 'S')
			specifier->type = 's';
		if (no_dot && ft_strchr("csidouxXp", specifier->type)
		&& specifier->precision == 0)
			specifier->precision = DOT_ZERO;
		if (!no_dot && specifier->type == 'f' && specifier->precision == 0)
			specifier->precision = 6;
	}
	else
		return (false);
	return (true);
}
