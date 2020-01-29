/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_xX.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/02 12:36:11 by krioliin       #+#    #+#                */
/*   Updated: 2019/07/19 20:34:53 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_hexadecimal(t_format_spec *s, t_placeholder *result)
{
	int		i;

	i = 0;
	if (!s->flag_hash || !s->flag_zero
	|| !ft_strchr("xX", s->type) ||
	(s->flag_hash && s->flag_minus && s->flag_zero))
		return ;
	result->str[1] = ' ';
	while (result->str[i + 2])
	{
		if (result->str[i + 2] == '0')
		{
			result->str[i] = '0';
			result->str[i + 1] = s->type;
			break ;
		}
		i++;
	}
	if ((s->width < s->precision) && s->width)
		fix_bug(s, result);
}
