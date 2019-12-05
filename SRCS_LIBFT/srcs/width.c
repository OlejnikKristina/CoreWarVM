/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   width.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 13:39:30 by asulliva       #+#    #+#                */
/*   Updated: 2019/04/04 21:27:39 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_check_width(const char *format, int i, t_print *ptr)
{
	int		width;

	width = ft_atoi(&format[i]);
	while (ft_isdigit(format[i]))
		i++;
	if (width > 0)
		ptr->w = width;
	if (format[i] == '.')
		ft_check_precision(format, i, ptr);
	else
		ft_check_modifier(format, i, ptr);
}
