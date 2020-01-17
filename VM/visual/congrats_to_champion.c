/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   congrats_to_champion.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 20:28:32 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/17 15:41:29 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visual.h"

void	congrats_champion(WINDOW *wop, t_player *champiom)
{
	short i;
	short y;

	i = 1;
	y = 0;
	while (y < 50)
	{
		i = 1;
		while (i <= 5)
		{
			usleep(100000);
			wattron(wop, COLOR_PAIR(i));
			mvwprintw(wop, 1, 2, "CONGRATULATIONS !!!");
			mvwprintw(wop, 2, 2, "The winner is ...");
			mvwprintw(wop, 2 + 1, 2, "Great \"%s\"", champiom->name);
			mvwprintw(wop, 2 + 2, 2, "%s", champiom->comment);
			wrefresh(wop);
			wattroff(wop, COLOR_PAIR(champiom->id));
			i++;
		}
		y++;
	}
}
