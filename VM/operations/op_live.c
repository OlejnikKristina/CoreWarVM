/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_live.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 13:44:31 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/11 17:28:23 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

bool		op_live(t_cursor *cursor, t_vm *vm)
{
	int		val;

	val = convert(&vm->arena[cursor->pos + 1], 4);
	if (val == cursor->id * -1)
	{
		cursor->last_live = vm->current_cycle;
		vm->nbr_lives++;
		vm->last_alive = cursor->id;
		ft_printf("LA: %d\n", vm->last_alive);
	}
	return (true);
}
