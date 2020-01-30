/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_pause.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 18:01:47 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/28 16:47:43 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visual.h"

/*
** Program will execute step by step with pressed Enter
*/

void	step_by_step(void)
{
	while (getchar() == ' ')
		;
	flushinp();
}

void	add_pause(WINDOW *winfo)
{
	int	key_pressed;

	key_pressed = getch();
	if (key_pressed == ' ')
	{
		mvwprintw(winfo, HEIGHT + 1, OFFSETX, "*** Pause ***       ");
		mvwprintw(winfo, HEIGHT + 2, OFFSETX, "Press ENTER to continue ...");
		wrefresh(winfo);
		keypad(stdscr, true);
		while (key_pressed != '\n')
			key_pressed = getch();
	}
	mvwprintw(winfo, HEIGHT + 1, OFFSETX, "*** Game running ***");
	mvwprintw(winfo, HEIGHT + 2, OFFSETX, "Press SPACE for a pause ...");
	wrefresh(winfo);
	flushinp();
}
