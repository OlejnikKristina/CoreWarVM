/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_live_calls.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 18:52:49 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/15 14:49:16 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_visual.h"

void	display_live_calls_init(WINDOW *winfo, short player_amnt)
{
	int		i;

	i = 1;
	while (i <= player_amnt)
	{
		wattron(winfo, COLOR_PAIR(i));
		mvwprintw(winfo, OFFSETY + i * 4 + 2, 32, "%d", 0);
		mvwprintw(winfo, OFFSETY + i * 4 + 1, 32, "%d", 0);
		i++;
	}
}

void	display_live_calls(WINDOW *winfo, t_cursor *cursor)
{
	wattron(winfo, COLOR_PAIR(cursor->id));
	mvwprintw(winfo, OFFSETY + cursor->id * 4 + 2, 32, "%d", cursor->last_live);
	mvwprintw(winfo, OFFSETY + cursor->id * 4 + 1, 32, "%d", cursor->lives_reported);
	wrefresh(winfo);
}
