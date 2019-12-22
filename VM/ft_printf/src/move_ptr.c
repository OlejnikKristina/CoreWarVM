/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move_ptr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 23:54:18 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/27 20:47:40 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	move_ptr(char **input, char move_to, t_output *out)
{
	size_t	len;

	out->usage = findchr(*input, move_to);
	*input += findchr(*input, move_to);
}
