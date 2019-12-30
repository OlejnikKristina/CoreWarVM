/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   go_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/01 15:16:31 by rvan-ket       #+#    #+#                */
/*   Updated: 2019/04/04 21:20:42 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	go_printf(va_list ap, t_print *ptr)
{
	if (ptr->con == 'c')
		go_print_c(ap, ptr);
	else if (ptr->con == 's')
		handle_s(ap, ptr);
	else if (ptr->con == '%')
		handle_modulo(ptr);
	else if (ptr->con == 'p')
		handle_p(ap, ptr);
	else if (ptr->con == 'f')
		get_arg_f(ap, ptr);
	else if (ptr->con == 'u')
		handle_u(ap, ptr);
	else if (ptr->con == 'o')
		handle_o(ap, ptr);
	else if (ptr->con == 'X')
		handle_sx(ap, ptr);
	else if (ptr->con == 'x')
		handle_sx(ap, ptr);
	else if (ptr->con == 'd')
		get_arg_d(ap, ptr);
	else if (ptr->con == 'i')
		get_arg_d(ap, ptr);
}
