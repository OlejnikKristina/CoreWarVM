/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_endian.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 21:15:27 by abumbier       #+#    #+#                */
/*   Updated: 2020/01/05 17:00:03 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

/*
**	@desc	- functions swap 4 bytes between little and big endian
**	@param	- int num, decimal number to be swapped
**	@return	- int swap, swapped number
*/

int		swap_4_bytes(int num)
{
	int	swap;

	swap = ((num >> 24) & 0xff) | ((num << 8) & 0xff0000) |
			((num >> 8) & 0xff00) | ((num << 24) & 0xff000000);
	return (swap);
}

/*
**	@desc	- function swaps 2 bytes between little and big endian
**	@param	- int num, decimal number to be swapped
**	@return	- int swap, swapped number
*/

short	swap_2_bytes(short nb)
{
	int b1;
	int b2;

	b1 = (nb & 0x00ff) << 8;
	b2 = (nb & 0xff00) >> 8;
	return (b1 | b2);
}
