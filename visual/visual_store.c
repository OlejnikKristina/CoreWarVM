/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual_store.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 18:44:43 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/28 18:44:57 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visual.h"

void	get_xy_coordinates(int *x, int *y, int address)
{
	*y = address / 64 + OFFSETY + 1;
	*x = (address % 64) * 3 + OFFSETX;
}

void	visual_store(WINDOW *warena, uint8_t arena[MEM_SIZE], short id,
		int address)
{
	int		x;
	int		y;
	int		pos;
	short	i;

	i = 0;
	wattron(warena, (COLOR_PAIR(id * 10 + 1) | A_DIM));
	while (i < 4)
	{
		pos = address + i;
		while (MEM_SIZE <= pos)
			pos -= MEM_SIZE;
		get_xy_coordinates(&x, &y, pos);
		mvwprintw(warena, y, x, "%.2x ", arena[pos]);
		i++;
	}
	wrefresh(warena);
	wattroff(warena, (COLOR_PAIR(id * 10 + 1) | A_DIM));
}
