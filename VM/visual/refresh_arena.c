/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   refresh_arena.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 18:31:29 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/11 19:31:38 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visual.h"

// void	display_cursors(WINDOW *warena, t_cursor *cursors,
// 		uint8_t arena[MEM_SIZE], short players_amnt)
// {
// 	t_cursor	*cursor;
// 	int			attribute;
// 	int			i;

// 	i = 1;
// 	cursor = cursors;
// 	while (cursor)
// 	{
// 		attribute = COLOR_PAIR(players_amnt - cursor->id + 1) * 10);
// 		cursor = cursor->next;
// 	}
// 	wattron(warena, COLOR_PAIR(players_amnt - cursor->id + 1 * 10));
// 	mvwprintw(warena, OFFSETY + i, 3, "%.2x", arena[cursor->pos]);

// 	wattroff(warena, COLOR_PAIR(100));
// 	wrefresh(warena);
// }

void	refresh_arena(t_vm *vm)
{
		// usleep(DELAY);
		// wmove(warena, 6, 3);
		// display_cursors(vm->v->warena, vm->cursor, vm->arena, vm->players_amnt);
		display_current_cycle(vm->v->winfo, vm->current_cycle);
		display_processes(vm->v->winfo, vm->process);
		wrefresh(vm->v->winfo);
}

