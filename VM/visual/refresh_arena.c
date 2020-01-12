/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   refresh_arena.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 18:31:29 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/12 20:06:39 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visual.h"

// attribute = COLOR_PAIR((players_amnt - cursor->id + 1) * 10);

void	display_cursors(WINDOW *warena, t_cursor *cursors,
		uint8_t arena[MEM_SIZE], short players_amnt)
{
	t_cursor	*cursor;
	int			next_player;
	int			y;
	int			x;
	int			i;

	i = players_amnt - 1;
	cursor = cursors;
	while (cursor)
	{
		next_player = ((HEIGHT) / players_amnt) * i;
		wattron(warena, COLOR_PAIR((i + 1) * 10));
		if (i != 0)
			x = cursor->pos % 64;
		else
			x = cursor->pos;
		if (64 <= x)
		{
			y = x / 64;
			x %= 64;
		}
		else
			y = 0;
		mvwprintw(warena, OFFSETY + 1 + next_player + y - i, x * 3 + 3, "%.2x ", arena[cursor->pos]);
		wrefresh(warena);
		cursor = cursor->next;
		i--;
	}
}

void	refresh_arena(t_vm *vm)
{
		usleep(DELAY);
		display_cursors(vm->v->warena, vm->cursor, vm->arena, vm->players_amnt);
		display_current_cycle(vm->v->winfo, vm->current_cycle);
		display_processes(vm->v->winfo, vm->process);
		wrefresh(vm->v->winfo);
		wrefresh(vm->v->warena);
}

