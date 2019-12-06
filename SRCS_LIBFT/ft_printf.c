/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 16:47:45 by tmeulenb       #+#    #+#                */
/*   Updated: 2019/04/08 17:02:16 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

t_print		*ft_newlist(void)
{
	t_print			*newlist;

	newlist = (t_print *)malloc(sizeof(t_print));
	if (!newlist)
		return (NULL);
	return (newlist);
}

void		*ft_check_flag(const char *format, int i, t_print *ptr)
{
	while (FLAGCHECK(format[i]))
	{
		if (format[i] == '+')
			ptr->plus = 1;
		else if (format[i] == '-')
			ptr->minus = 1;
		else if (format[i] == ' ')
			ptr->sp = 1;
		else if (format[i] == '0')
			ptr->zero = 1;
		else if (format[i] == '#')
			ptr->hash = 1;
		i++;
	}
	if (format[i] == '.')
		ft_check_precision(format, i, ptr);
	ft_check_width(format, i, ptr);
	return (0);
}

void		ft_check_arg(const char *format, int i, t_print *ptr)
{
	ft_flags_to_zero(ptr);
	ft_check_flag(format, i + 1, ptr);
}

void		ft_printf_loop(char const *format, va_list ap, t_print *ptr)
{
	int			i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_check_arg(format, i, ptr);
			i = ptr->i;
			go_printf(ap, ptr);
		}
		else
		{
			ptr->g_count += 1;
			ft_putchar(format[i]);
		}
		i++;
	}
}

int			ft_printf(char const *format, ...)
{
	int			i;
	va_list		ap;
	t_print		*ptr;

	ptr = ft_newlist();
	i = 0;
	ptr->g_count = 0;
	va_start(ap, format);
	ft_printf_loop(format, ap, ptr);
	i = ptr->g_count;
	va_end(ap);
	free(ptr);
	return (i);
}
