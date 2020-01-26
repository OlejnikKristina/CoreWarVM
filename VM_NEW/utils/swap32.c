/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap32.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 13:29:02 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/22 15:53:28 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function swaps bits in 4 bytes
**	@paran	- int nb, number to be swapped
**	@return	- the swapped number
*/

int		swap_32(int nb)
{
	int b1;
	int b2;
	int b3;
	int b4;

	b1 = (nb & 0x000000ff) << 24;
	b2 = (nb & 0x0000ff00) << 8;
	b3 = (nb & 0x00ff0000) >> 8;
	b4 = (nb & 0xff000000) >> 24;
	return (b1 | b2 | b3 | b4);
}
