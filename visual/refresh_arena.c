/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   refresh_arena.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 18:31:29 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/16 18:20:14 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visual.h"

/*
** Program will execute step by step with pressed Enter
*/

void	step_by_step()
{
	while(getchar() == ' ')
		;
	flushinp();
}

bool	make_blink(WINDOW *warena , t_cursor *cursor)
{
	wattron(warena, COLOR_PAIR(cursor->id));
	mvwprintw(warena, cursor->prev_xy[1],
	cursor->prev_xy[0], "%.2x", cursor->prev_val);
	return (true);
}

bool	rm_prev_cursor_position(t_vm *vm, t_cursor *cursor,
		int current_x, int current_y)
{
	static int blink_counter[42];

	if (cursor->prev_xy[0] == -1 || cursor->prev_xy[1] == -1)
	{
		cursor->prev_xy[0] = current_x;
		cursor->prev_xy[1] = current_y;
		cursor->prev_val = vm->arena[cursor->pos];
		blink_counter[cursor->id] += 1;
	}
	else if (cursor->prev_xy[0] != current_x || cursor->prev_xy[1] != current_y)
	{
		wattron(vm->v->warena, COLOR_PAIR(cursor->id));
		mvwprintw(vm->v->warena, cursor->prev_xy[1],
		cursor->prev_xy[0], "%.2x", cursor->prev_val);
		wrefresh(vm->v->warena);
		cursor->prev_xy[0] = current_x;
		cursor->prev_xy[1] = current_y;
		blink_counter[cursor->id] = 0;
		cursor->prev_val = vm->arena[cursor->pos];
	}
	else
	{
		blink_counter[cursor->id] += 1;
		if (25 <= blink_counter[cursor->id] && blink_counter[cursor->id] <= 35)
		{
			make_blink(vm->v->warena, cursor);
			return (true);
		}
		else if (35 <= blink_counter[cursor->id])
			blink_counter[cursor->id] = 0;
	}
	return (false);
}

void	display_cursors(WINDOW *warena, t_cursor *cursors,
		uint8_t arena[MEM_SIZE], t_vm *vm)
{
	bool		blink;
	int			y;
	int			x;
	t_cursor	*cursor;

	cursor = cursors;
	while (cursor)
	{
		get_xy_coordinates(&x, &y, cursor->pos);
		blink = rm_prev_cursor_position(vm, cursor, x, y);
		if (blink == false)
		{
			wattron(warena, COLOR_PAIR((cursor->id) * 10));
			mvwprintw(warena, y, x, "%.2x", arena[cursor->pos]);
		}
		wrefresh(warena);
		cursor = cursor->next;
	}
}

void	refresh_arena(t_vm *vm)
{
	if (DEBUG_MOD)
		step_by_step();
	else
		add_pause(vm->v->winfo);
	usleep(DELAY);
	display_cursors(vm->v->warena, vm->cursor, vm->arena, vm);
	display_current_cycle(vm->v->winfo, vm->current_cycle);
	display_processes(vm->v->winfo, vm->process);
	wrefresh(vm->v->winfo);
	wrefresh(vm->v->warena);
}

