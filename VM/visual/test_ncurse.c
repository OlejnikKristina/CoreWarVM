/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ncurse.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 15:26:21 by krioliin       #+#    #+#                */
/*   Updated: 2019/12/30 15:25:23 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_visual.h>

void	move_ball()
{
	int x;
	int y;
	int	max_x;
	int	max_y;
	int	direction;
	int	next_x;

	direction = 1;
	next_x = 0;
	max_x = 0;
	max_y = 0;
	x = 0;
	y = 0;
	while (x < 300)
	{
		getmaxyx(stdscr, max_y, max_x);
		mvprintw(y, x, "o");
		refresh();
		usleep(30000);
		x++;
		next_x = x + direction;
 		if (next_x >= max_x || next_x < 0)
 			direction*= -1;
		else
 			x+= direction;
	}	
}

bool	visual_corawar()
{
	int	ch;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	printw("Type any character to see it in bold\n");
	ch = getch();
	if (ch == KEY_F(1))
		printw("F1 Key pressed");
	else
	{
		printw("Key pressed: ");
		attron(A_BOLD);
		printw("%c", ch);
		attroff(A_BOLD);
	}
	refresh();
	getch();
	endwin();
	return (true);
}

