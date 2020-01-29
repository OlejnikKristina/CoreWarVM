/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_flag.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 23:29:00 by krioliin       #+#    #+#                */
/*   Updated: 2019/07/19 20:41:27 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		hex_flag_hash(t_format_spec *s, t_placeholder *spec_res,
char *num)
{
	if (!s->flag_zero || s->flag_minus || (s->width <= (ft_strlen(num) + 2)))
	{
		spec_res->str = ft_superjoin(&spec_res->str, "0x");
		if (s->type == 'X')
			spec_res->str[ft_strlen(spec_res->str) - 1] = 'X';
	}
}

void			int_flag(t_format_spec *s, t_placeholder *spec_res, char *num)
{
	if (s->is_negative && (!s->flag_zero || s->precision))
		spec_res->str = ft_superjoin(&spec_res->str, "-");
	else if (s->flag_plus && (!s->flag_zero || s->precision ||
	(s->flag_zero && s->width < s->dig_amount)) && !s->is_negative)
		spec_res->str = ft_superjoin(&spec_res->str, "+");
	else if (s->flag_space && !s->flag_zero)
		spec_res->str = ft_superjoin(&spec_res->str, " ");
	if (s->flag_hash && ft_strchr("xX", s->type) && ft_strcmp(num, "0"))
		hex_flag_hash(s, spec_res, num);
	if (s->type == 'o' && s->flag_hash && ft_strcmp(num, "0"))
		spec_res->str = ft_superjoin(&spec_res->str, "0");
}

void			int_flag_minus(t_format_spec *s, t_placeholder *result)
{
	int		width;
	char	*set_width;

	if (s->is_negative && (s->flag_plus || s->flag_space))
		s->flag_space = false;
	if (s->flag_hash && s->flag_zero && ft_strchr("xX", s->type)
	&& (s->dig_amount - s->precision) < s->width)
		result->str[1] = s->type;
	if (s->precision <= s->dig_amount)
		width = s->width - s->dig_amount -
		((s->flag_plus && !s->is_negative) || s->flag_space);
	else
		width = s->width - s->precision
		- ((s->flag_plus && !s->is_negative) || s->flag_space);
	(s->flag_space && s->flag_plus) ? (width++) : 1;
	if (s->flag_space && s->is_negative)
		width++;
	if (s->flag_space && s->is_negative && s->flag_plus)
		width++;
	if (!s->flag_minus || width <= 0)
		return ;
	set_width = ft_strnew(width + 1);
	set_width = ft_memset((void *)set_width, ' ', width);
	result->str = ft_superjoin(&result->str, set_width);
	ft_strdel(&set_width);
}
