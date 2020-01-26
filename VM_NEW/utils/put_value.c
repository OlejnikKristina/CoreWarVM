/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_value.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 19:54:55 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/22 20:10:26 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function puts value into arena
**	@param	- t_byte *arena, arena to write to
**			- int index, starting index
**			- void *val, void pointer of value to write
*/

void	put_value(t_byte *arena, int index, void *val)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		arena[get_index(index, i)] = ((t_byte*)val)[i];
		i++;
	}
}
