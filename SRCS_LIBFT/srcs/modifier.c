/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   modifier.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 14:44:53 by awehlbur       #+#    #+#                */
/*   Updated: 2019/04/03 14:46:58 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_check_modifier(const char *format, int i, t_print *ptr)
{
	if (format[i] == 'l' && format[i + 1] == 'l')
		ptr->ll = 1;
	if (format[i] == 'h' && format[i + 1] == 'h')
		ptr->hh = 1;
	if (format[i] == 'L')
		ptr->big_l = 1;
	if (format[i] == 'l')
		ptr->l = 1;
	if (format[i] == 'h')
		ptr->h = 1;
	if (format[i] == 'z')
		ptr->z = 1;
	if (format[i] == 'j')
		ptr->j = 1;
	if (ptr->ll || ptr->hh)
		i += 2;
	else if (ptr->l || ptr->h || ptr->big_l || ptr->z || ptr->j)
		i++;
	ft_check_conversion(format, i, ptr);
}
