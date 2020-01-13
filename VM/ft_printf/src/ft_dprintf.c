/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dprintf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 00:12:30 by krioliin       #+#    #+#                */
/*   Updated: 2019/07/15 18:38:55 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_dprintf(const int fd, const char *format, ...)
{
	va_list		arg_ptr;
	t_output	out;
	char		*input;

	va_start(arg_ptr, format);
	input = ft_strdup(format);
	out.usage = 0;
	out.str = ft_strnew(0);
	if (read_input(input, arg_ptr, &out) == FINISHED)
		if (out.str)
		{
			ft_putstr_fd(out.str, fd);
			out.usage += ft_strlen(out.str);
			ft_strdel(&out.str);
		}
	ft_strdel(&input);
	return (out.usage);
}
