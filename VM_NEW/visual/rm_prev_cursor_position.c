/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rm_prev_cursor_position.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 18:42:17 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/29 15:42:18 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visual.h"

bool	make_blink(WINDOW *warena, t_cursor *cursor)
{
	wattron(warena, COLOR_PAIR(cursor->reg[0] * -1));
	mvwprintw(warena, cursor->prev_xy[1],
	cursor->prev_xy[0], "%.2x", cursor->prev_val);
	return (true);
}

/*
** init_previous_xy initializes previous position of coursor
** cursor->prev_val - caracter from previos cursor position
*/

bool	init_previous_xy(t_cursor *cursor, int curren_x, int curren_y, int pos)
{
	if (cursor->prev_xy[0] == -1 || cursor->prev_xy[1] == -1)
	{
		cursor->prev_xy[0] = curren_x;
		cursor->prev_xy[1] = curren_y;
		cursor->prev_val = pos;
		return (true);
	}
	return (false);
}

bool	cursor_moved(t_cursor *cursor, t_vm *vm, int current_x, int current_y)
{
	if (cursor->prev_xy[0] != current_x || cursor->prev_xy[1] != current_y)
	{
		wattron(vm->v->warena, COLOR_PAIR(cursor->reg[0] * -1));
		mvwprintw(vm->v->warena, cursor->prev_xy[1],
		cursor->prev_xy[0], "%.2x", cursor->prev_val);
		wrefresh(vm->v->warena);
		cursor->prev_xy[0] = current_x;
		cursor->prev_xy[1] = current_y;
		cursor->prev_val = vm->arena[cursor->pos];
		return (true);
	}
	return (false);
}

/*
** @rm_prev_cursor_position();
** Detect if position of cursor has been changed
** If so, remove previous mapping from arena
** @blink_counter - trecker amount of cycles cursor stand on the same place
** If cursor dosn't change position during 10 cycles, it's blink
*/

bool	rm_prev_cursor_position(t_vm *vm, t_cursor *cursor,
		int current_x, int current_y)
{
	static int blink_counter[42];

	if (init_previous_xy(cursor, current_x, current_y, vm->arena[cursor->pos]))
		blink_counter[cursor->id] += 1;
	else if (cursor_moved(cursor, vm, current_x, current_y))
		blink_counter[cursor->id] = 0;
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
			wattron(warena, COLOR_PAIR((cursor->reg[0] * -1) * 10));
			mvwprintw(warena, y, x, "%.2x", arena[cursor->pos]);
		}
		wrefresh(warena);
		cursor = cursor->next;
	}
}
