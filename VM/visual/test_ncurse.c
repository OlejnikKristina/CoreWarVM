/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ncurse.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 15:26:21 by krioliin       #+#    #+#                */
/*   Updated: 2019/12/30 19:07:29 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_visual.h>

void	move_ball()
{
	int x;
	int y;

	x = 0;
	y = 0;
	addch( 'A' | A_BOLD | A_UNDERLINE );
	// while (x < 300)
	// {
	// 	mvprintw(y, x, "o");
	// 	refresh();
	// 	usleep(30000);
	// 	x++;
	// }
	addch( 'A' | A_BOLD | A_UNDERLINE );
}

void	init_pairs()
{
	if (!has_colors())
	{
		endwin();
		ft_printf("Your terminal does't support color\n");
	}
	start_color();
	init_pair(COLOR_P1, DARCK_RED, COLOR_RED);
	init_pair(BGBLUE_FYELLOW, LIGHT_BLUE, COLOR_YELLOW);
	init_pair(BGGREEN_FGRED, COLOR_RED, COLOR_GREEN);
	init_pair(BGCYAN_FBLACK, COLOR_CYAN, COLOR_BLACK);
	init_pair(BGRED_FBLACK, COLOR_RED, COLOR_BLACK);
}

void	init_arena(int	height, int width, int startx, int starty)
{
	WINDOW	*arena;

	wbkgd(stdscr, COLOR_PAIR(BGRED_FBLACK));
	refresh();

	arena = newwin(height, width, startx, starty);
	wbkgd(arena, COLOR_PAIR(BGRED_FBLACK));
	wborder(arena, '*', '*', '*','*','#', '#', '#', '#');
	mvaddstr(OFFSETY + 3, OFFSETX + ((width / 2) - 10), "[ CORE WAR ]");
	wrefresh(arena);
	refresh();
	delwin(arena);
}

bool	visual_corawar(t_vm *vm)
{
	initscr();
	refresh();
	init_pairs();
	init_arena(HEIGHT, WIDTH, OFFSETX, OFFSETY);
	if (vm)
		;
	// display_battlefield(vm->arena);
	// printw("Hello world!");
	// move_ball();
	refresh();
	getch();
	endwin();
	return (true);
}

