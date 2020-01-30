/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_zjmp.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 21:32:32 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/30 21:32:33 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

bool		op_zjmp(t_cursor *cursor, t_vm *vm)
{
	if (cursor->carry == 1)
	{
		cursor->pc = convert(&vm->arena[((cursor->pos + 1) % MEM_SIZE)], 2) % IDX_MOD;
	}
	return (true);
}
