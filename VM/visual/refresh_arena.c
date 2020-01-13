/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   refresh_arena.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 18:31:29 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/13 13:54:56 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visual.h"

// void	display_cursors(WINDOW *warena, t_cursor *cursors,
// 		uint8_t arena[MEM_SIZE], short players_amnt)
// {
// 	t_cursor	*cursor;
// 	int			next_player;
// 	int			y;
// 	int			x;
// 	int			i;

// 	i = players_amnt - 1;
// 	cursor = cursors;
// 	while (cursor)
// 	{
// 		next_player = ((HEIGHT) / players_amnt) * i;
			
// 		if (i != 0)
// 			x = cursor->pos % 64;
// 		else
// 			x = cursor->pos;
// 		if (64 <= x)
// 		{
// 			y = x / 64;
// 			x %= 64;
// 		}
// 		else
// 			y = 0;
// 		mvwprintw(warena, OFFSETY + 1 + next_player + y - i, x * 3 + 3, "%.2x ", arena[cursor->pos]);
// 		wrefresh(warena);
// 		cursor = cursor->next;
// 		i--;
// 	}
// }

// void	init_prev_xycoordinate(int xy[100][2], t_cursor *cursors)
// {
// 	int			i;
// 	t_cursor	*cursor;

// 	i = 0;
// 	cursor = cursors;
// 	while (i < 100 && cursor)
// 	{

// 		cursor = cursor->next;
// 		i++;
// 	}
// }

// void	rm_prev_cursor_pos(t_cursor *cursors)
// {
// 	static int xy[100][2];

// 	init_prev_xy_coordinate(xy, cursors);
// }

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
		wattron(vm->v->warena, COLOR_PAIR(1));
		mvwprintw(vm->v->warena, OFFSETY + cursor->prev_xy[1] + 1,
		OFFSETX + cursor->prev_xy[0] * 3, "%.2x ", cursor->prev_val);
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
		OFFSETX + x * 3, "%.2x ", arena[cursor->pos]);
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

