/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   defines.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/07 19:43:26 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/04/07 19:43:53 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		checkchar(char x)
{
	if (x == 'c' || x == 's' || x == 'p' || x == 'C' || x == 'S' || x == 'P')
		return (1);
	return (0);
}

int		checkint(char x)
{
	if (x == 'd' || x == 'i' || x == 'u' || x == 'D' || x == 'I' || x == 'U')
		return (1);
	return (0);
}
