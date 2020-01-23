/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_live.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 13:44:31 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/23 14:13:50 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

bool		op_live(t_cursor *cursor, t_vm *vm)
{
	int		val;
	int		index;

	val = convert(&vm->arena[(cursor->pos + 1) % MEM_SIZE], 4);
	cursor->last_live = vm->current_cycle;
	if (cursor->reg[0] == val)
	{
		index = get_player_index(vm->players, val, vm->players_amnt);
		vm->players[index]->lives++;
		vm->players[index]->last_live = vm->current_cycle;
		vm->nbr_lives++;
		vm->last_alive = (val < 0) ? val * -1 : val;
		if (vm->flag->v)
			display_live_calls(vm->v->winfo, vm->players[index], vm->cycles_passed);
	}
	return (true);
}
