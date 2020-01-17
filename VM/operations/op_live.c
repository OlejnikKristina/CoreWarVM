/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_live.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 13:44:31 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/17 19:57:53 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

bool		op_live(t_cursor *cursor, t_vm *vm)
{
	int		val;
	int		id;

	val = convert(&vm->arena[cursor->pos + 1], 4);
	val = (val < 0 ? val * -1 : val);
	cursor->last_live = vm->current_cycle;
	if (val > 0 && val <= vm->players_amnt)
	{
		id = get_player_id(vm->players, val, vm->players_amnt);
		vm->players[id]->lives++;
		vm->players[id]->last_live = cursor->last_live;
		vm->nbr_lives++;
		vm->last_alive = val;
		if (vm->flag->v)
			display_live_calls(vm->v->winfo, vm->players[id]);
	}
	return (true);
}
