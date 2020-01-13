/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   refresh_arena.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 18:31:29 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/13 14:25:10 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visual.h"

void	rm_prev_cursor_position(t_vm *vm, t_cursor *cursor,
		int current_x, int current_y)
{
	if (cursor->prev_xy[0] == -1 || cursor->prev_xy[1] == -1)
	{
		cursor->prev_xy[0] = current_x;
		cursor->prev_xy[1] = current_y;
		cursor->prev_val = vm->arena[cursor->pos];
	}
	else if (cursor->prev_xy[0] != current_x || cursor->prev_xy[1] != current_y)
	{
		wattron(vm->v->warena, COLOR_PAIR(cursor->id));
		mvwprintw(vm->v->warena, OFFSETY + cursor->prev_xy[1] + 1,
		OFFSETX + cursor->prev_xy[0] * 3, "%.2x", cursor->prev_val);
		wrefresh(vm->v->warena);
		cursor->prev_xy[0] = current_x;
		cursor->prev_xy[1] = current_y;
		cursor->prev_val = vm->arena[cursor->pos];
	}
}

void	display_cursors(WINDOW *warena, t_cursor *cursors,
		uint8_t arena[MEM_SIZE], t_vm *vm)
{
	t_cursor	*cursor;
	int			approximate_y;
	int			accurate_y;
	int			diff;
	int			x;

	cursor = cursors;
	while (cursor)
	{
		approximate_y = cursor->pos / 64;
		diff = approximate_y / 16;
		accurate_y = approximate_y;
		x = cursor->pos % 64;
		rm_prev_cursor_position(vm, cursor, x, accurate_y);
		wattron(warena, COLOR_PAIR((cursor->id) * 10));
		mvwprintw(warena, OFFSETY + accurate_y + 1,
		OFFSETX + x * 3, "%.2x", arena[cursor->pos]);
		wrefresh(warena);
		cursor = cursor->next;
	}
}

void	refresh_arena(t_vm *vm)
{
		usleep(DELAY);
		display_cursors(vm->v->warena, vm->cursor, vm->arena, vm);
		display_current_cycle(vm->v->winfo, vm->current_cycle);
		display_processes(vm->v->winfo, vm->process);
		wrefresh(vm->v->winfo);
		wrefresh(vm->v->warena);
}

