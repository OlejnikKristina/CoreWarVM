/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vinit_cursors.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 14:39:50 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/05 15:15:10 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_visual.h"

// static void	vdisplay_arena(t_vm *vm, WINDOW *warena)
// {
// 	int		yx[2];
// 	int		i;
// 	int		attribute;
// 	short	num;

// 	i = 0;
// 	yx[0] = 1;
// 	num = 0;
// 	wmove(warena, OFFSETY + 1, 3);
// 	while (i < MEM_SIZE - 1)
// 	{
// 		yx[1] = 0;
// 		while (yx[1] < WIDTH / 3 - 4)
// 		{
// 			attribute = get_attribute(i, vm->players, vm->players_amnt);
// 			wattron(warena, attribute);
// 			wprintw(warena, "%.2x ", vm->arena[i]);
// 			i++;
// 			yx[1] += 3;
// 		}
// 		yx[0] += 1;
// 		wmove(warena, OFFSETY + yx[0], 2);
// 		wprintw(warena, " ");
		
// 	}
// 	wrefresh(warena);
// }

void	display_cursors(WINDOW *warena, t_cursor *cursor)
{
	if (cursor)
		;
	wattron(warena, COLOR_PAIR(4));
	wmove(warena, 6, 3);
	wprintw(warena, "HH");
	wrefresh(warena);
	mvwprintw(warena, 6, 3, "HH");
	wrefresh(warena);
}
