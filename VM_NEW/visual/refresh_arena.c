/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   refresh_arena.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 18:31:29 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/29 15:15:27 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visual.h"

void	refresh_arena(t_vm *vm)
{
	add_pause(vm->v->winfo);
	usleep(DELAY);
	display_cursors(vm->v->warena, vm->game->cursors, vm->arena, vm);
	display_current_cycle(vm->v->winfo, vm->game->cycles);
	display_cycle_passed(vm->v->winfo, vm->game->cycles);
	display_processes(vm->v->winfo, vm->game->processes);
	wrefresh(vm->v->winfo);
	wrefresh(vm->v->warena);
}
