/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_bytes.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 18:51:42 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/26 16:40:22 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function reads bytes
**	@param	- t_byte *arena, arena to read from
**			- int idx, start index
**			- int amount, amount of bytes to read
**	@return	- int value, value of amount read
*/

int			get_bytes(t_byte *arena, int idx, int amount)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (i < amount)
	{
		value <<= 8;
		value = value | arena[get_index(idx, i)];
		i++;
	}
	if (amount == 2)
		return ((short)value);
	return (value);
}
