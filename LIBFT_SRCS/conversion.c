/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversion.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 15:28:03 by tmeulenb       #+#    #+#                */
/*   Updated: 2019/04/04 21:20:20 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_int_conversion(const char *format, int i, t_print *ptr)
{
	if (format[i] == 'd' || format[i] == 'D')
		ptr->con = 'd';
	else if (format[i] == 'i' || format[i] == 'I')
		ptr->con = 'i';
	else if (format[i] == 'u' || format[i] == 'U')
		ptr->con = 'u';
	ptr->i = i;
}

void	ft_check_char_conversion(const char *format, int i, t_print *ptr)
{
	if (format[i] == 'c' || format[i] == 'C')
		ptr->con = 'c';
	else if (format[i] == 's' || format[i] == 'S')
		ptr->con = 's';
	else if (format[i] == 'p' || format[i] == 'P')
		ptr->con = 'p';
	ptr->i = i;
}

void	ft_check_int_base_conversions(const char *format, int i, t_print *ptr)
{
	if (format[i] == 'x')
		ptr->con = 'x';
	else if (format[i] == 'X')
		ptr->con = 'X';
	else if (format[i] == 'o' || format[i] == 'O')
		ptr->con = 'o';
	ptr->i = i;
}

void	ft_check_f_conversion(const char *format, int i, t_print *ptr)
{
	if (format[i] == 'f' || format[i] == 'F')
		ptr->con = 'f';
	ptr->i = i;
}

void	ft_check_conversion(const char *format, int i, t_print *ptr)
{
	if (checkchar(format[i]))
		ft_check_char_conversion(format, i, ptr);
	else if (checkint(format[i]))
		ft_check_int_conversion(format, i, ptr);
	else if (CHECKBASE(format[i]))
		ft_check_int_base_conversions(format, i, ptr);
	else if (CHECKF(format[i]))
		ft_check_f_conversion(format, i, ptr);
	else if (format[i] == '%')
	{
		ptr->con = '%';
		ptr->i = i;
	}
	else
		ptr->i = i + 1;
}
