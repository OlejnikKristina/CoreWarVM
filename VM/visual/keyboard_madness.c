/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard_madness.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 15:17:12 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/16 16:01:30 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visual.h"

/*
** Intresting ncrses function:
** wclear(warena);
** winsertln(warena);
** flushinp();
*/

void	keyboard_madness(WINDOW *warena)
{
	char buffer[100];

	noecho();
	wclear(warena);
	mvwprintw(warena, HEIGHT / 2, WIDTH / 2, "Let's battle begin!!!\n");
	wrefresh(warena);
	napms(3000);
	wclear(warena);
	mvwprintw(warena, HEIGHT / 2, WIDTH / 2, "Here what you typped\n");
	getnstr(buffer, 100);
	napms(3000);
	// wclear(warena);
	wrefresh(warena);
}
