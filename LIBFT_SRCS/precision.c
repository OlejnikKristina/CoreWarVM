/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   precision.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 13:29:32 by asulliva       #+#    #+#                */
/*   Updated: 2019/04/08 19:43:29 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_check_precision(const char *format, int i, t_print *ptr)
{
	int		prec;

	prec = 0;
	if (format[i] == '.')
	{
		i++;
		ptr->dot = 1;
		if (format[i] >= '0' && format[i] <= '9')
		{
			prec = ft_atoi(&format[i]);
			i += ft_nlen(prec);
		}
	}
	if (prec == 0)
	{
		ptr->pc = -1;
		ptr->npc = 1;
	}
	else
		ptr->pc = prec;
	ft_check_modifier(format, i, ptr);
}
