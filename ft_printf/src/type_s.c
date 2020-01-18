/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_s.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/27 20:48:44 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_space(unsigned dig_amount, char **result, ssize_t width)
{
	int			extra_zeros;
	char		*zeros_str;

	if (width < dig_amount)
		return ;
	extra_zeros = width - dig_amount;
	zeros_str = ft_strnew(extra_zeros);
	ft_memset(zeros_str, ' ', extra_zeros);
	if (!*result)
		*result = ft_strnew(0);
	*result = ft_superjoin(result, zeros_str);
	ft_strdel(&zeros_str);
	return ;
}

void	str_width(t_format_spec *s, t_placeholder *result, char *cut_str)
{
	int		len;

	len = ft_strlen(cut_str);
	if (!s->width || s->width <= len)
	{
		result->str = ft_strdup(cut_str);
		return ;
	}
	if (s->flag_minus)
	{
		result->str = ft_strdup(cut_str);
		add_space(len, &result->str, s->width);
	}
	else if (s->flag_zero)
	{
		add_zeros(len, &result->str, s->width);
		result->str = ft_superjoin(&result->str, cut_str);
	}
	else
	{
		add_space(len, &result->str, s->width);
		result->str = ft_superjoin(&result->str, cut_str);
	}
}

bool	type_s(t_format_spec *specifier, t_placeholder *result, va_list arg_ptr)
{
	char	*line;
	char	*holder;

	line = va_arg(arg_ptr, char *);
	if (line == NULL)
	{
		result->str = ft_strdup("(null)");
		return (true);
	}
	if (specifier->precision == -42)
		holder = ft_strnew(0);
	else if (specifier->precision)
		holder = ft_strsub((char const *)line, 0, specifier->precision);
	else
		holder = ft_strdup(line);
	str_width(specifier, result, holder);
	ft_strdel(&holder);
	return (true);
}
