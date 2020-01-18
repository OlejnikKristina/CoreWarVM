/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual_sti.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 14:24:42 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/16 15:26:00 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visual.h"

void	visual_sti(WINDOW *warena, uint8_t arena[], short id, int address)
{
	int		x;
	int		y;
	short	i;

	i = 0;
	wattron(warena, (COLOR_PAIR(id) | A_BOLD));
	while (i < 4)
	{
		get_xy_coordinates(&x, &y, address);
		mvwprintw(warena, y, x, "%.2x ", arena[i]);
		address++;
		i++;
	}
	wrefresh(warena);
}
