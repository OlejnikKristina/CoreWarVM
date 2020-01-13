/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual_sti.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 14:24:42 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/13 14:42:12 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visual.h"

void	get_xy_coordinate(int *x, int *y, int address)
{
	*y = address / 64 + OFFSETY + 1;
	*x = (address % 64) * 3 + OFFSETX;
}

/* t_visual v swap to WINDOW warena  */

void	visual_sti(t_visual *v, short id, int32_t val_to_write, int address)
{
	int	x;
	int	y;

	get_xy_coordinate(&x, &y, address);
	wattron(v->warena, (COLOR_PAIR(id) | A_BOLD));
	mvwprintw(v->warena, y, x, "%.2x ", val_to_write);
	wrefresh(v->warena);
}
