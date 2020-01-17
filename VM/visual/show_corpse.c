/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   show_corpse.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 20:45:20 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/17 15:46:03 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

void show_corpse(short dead_cursor_id, WINDOW *wop)
{
	if (dead_cursor_id && wop)
		;
	// wclear(wop);
	// wattron(wop, COLOR_RED);
	// mvwprintw(wop, WOPH - 2, 1,
	// "(X) Player (%d): -1 cursor", dead_cursor_id);
	// wattroff(wop, COLOR_RED);
	// wrefresh(wop);
}
