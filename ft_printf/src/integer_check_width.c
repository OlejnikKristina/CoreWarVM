/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   integer_check_width.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/02 12:36:11 by krioliin       #+#    #+#                */
/*   Updated: 2019/07/19 20:43:49 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool		check_width(t_format_spec *s)
{
	s->width += (s->flag_space && s->is_negative);
	if (!s->width || s->flag_minus ||
	s->width <= s->precision ||
	s->width <= s->dig_amount ||
	s->width <= (s->dig_amount - s->precision))
		return (false);
	if (s->flag_plus && !s->is_negative && !s->flag_space
	&& (!s->flag_zero || s->precision))
		s->width--;
	return (true);
}

void		fix_bug(t_format_spec *s, t_placeholder *result)
{
	char	*temp;

	result->str[1] = '0';
	temp = result->str;
	result->str = ft_strjoin("00", temp);
	ft_strdel(&temp);
	result->str[1] = s->type;
}

bool		need_crutch(t_format_spec *spec, uint64_t data)
{
	if (ft_strchr("uxX", spec->type) && data == 0 && spec->flag_minus
	&& spec->precision == 0 && spec->width == 0 && spec->flag_hash)
	{
		spec->precision = 0;
		return (true);
	}
	if (spec->precision == -42 && (spec->type != 'o' || !spec->flag_hash))
	{
		spec->precision = 0;
		spec->flag_hash = 0;
		return (true);
	}
	return (false);
}
