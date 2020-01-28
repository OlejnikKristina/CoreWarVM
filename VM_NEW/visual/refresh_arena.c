/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   refresh_arena.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 18:31:29 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/28 18:42:40 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visual.h"

void	refresh_arena(t_vm *vm)
{
	if (DEBUG_MOD)
		step_by_step();
	else
		add_pause(vm->v->winfo);
	usleep(DELAY);
	display_cursors(vm->v->warena, vm->cursor, vm->arena, vm);
	display_current_cycle(vm->v->winfo, vm->current_cycle);
	display_cycle_passed(vm->v->winfo, vm->cycle_counter);
	display_processes(vm->v->winfo, vm->process);
	wrefresh(vm->v->winfo);
	wrefresh(vm->v->warena);
}
