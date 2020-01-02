/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   corewar_visual.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 15:26:21 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/02 21:17:24 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_visual.h"

void	del_players_colors(t_pl_color ***pl_colors, short players_amnt)
{
	short i;

	i = 0;
	while (i < players_amnt)
	{
		free(*pl_colors[i]);
		i++;
	}
	*pl_colors = NULL;
}

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
		ft_printf("Your terminal does't support colors\n");
	}
	start_color();
	// init_pair(COLOR_P1, DARCK_RED, COLOR_RED);
	// init_pair(BGBLUE_FYELLOW, LIGHT_BLUE, COLOR_YELLOW);
	// init_pair(BGGREEN_FGRED, COLOR_RED, COLOR_GREEN);
	// init_pair(BGCYAN_FBLACK, COLOR_CYAN, COLOR_BLACK);
	init_pair(BGRED_FBLACK, COLOR_RED, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, INTENSE_PINK, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, LIGHT_BLUE, COLOR_BLACK);
	init_pair(5, DARCK_GREEN, COLOR_BLACK);
}

WINDOW	*init_arena(int	height, int width, int startx, int starty)
{
	WINDOW	*warena;

	wbkgd(stdscr, COLOR_PAIR(BGRED_FBLACK));
	refresh();

	warena = newwin(height, width, startx, starty);
	wbkgd(warena, COLOR_PAIR(BGRED_FBLACK));
	wborder(warena, '*', '*', '*','*','#', '#', '#', '#');
	mvaddstr(OFFSETY + 1, OFFSETX + ((width / 2) - 10), "[ CORE WAR ]");
	wrefresh(warena);
	return (warena);
}

int			get_attribute(int i, t_player **players, short players_amnt)
{
	static int		prev_code_size;
	static short	player_id;
	int				index;
	t_player		*player;

	index = (MEM_SIZE / players_amnt) * player_id;
	if (!(player = get_player(players, player_id + 1, players_amnt)))
		return (COLOR_PAIR(5) | A_BOLD);
	if (i - index >= player->code_size)
	{
		prev_code_size = player->code_size + index;
		player_id++;
	}
	else if (prev_code_size < i && i < index)
		return (COLOR_PAIR(5) | A_BOLD);
	else if (i - index < player->code_size && prev_code_size <= i)
		return (COLOR_PAIR(player_id + 1) | A_BOLD);
	return (COLOR_PAIR(5) | A_BOLD);
}

static void	display_arena(t_vm *vm, WINDOW *warena)
{
	int		yx[2];
	int		i;
	int		attribute;
	short	num;

	i = 0;
	yx[0] = 1;
	num = 0;
	wmove(warena, OFFSETY + 1, 3);
	while (i < MEM_SIZE - 1)
	{
		yx[1] = 0;
		while (yx[1] < WIDTH / 3 - 4)
		{
			attribute = get_attribute(i, vm->players, vm->players_amnt);
			wattron(warena, attribute);
			wprintw(warena, "%.2x ", vm->arena[i]);
			i++;
			yx[1] += 3;
		}
		yx[0] += 1;
		wmove(warena, OFFSETY + yx[0], 2);
		wprintw(warena, " ");
		
	}
	wrefresh(warena);
}

bool	visual_corawar(t_vm *vm)
{
	// t_pl_color	**players_colors;
	WINDOW		*warena;

	// players_colors = NULL;
	initscr();
	init_pairs();
	warena = init_arena(HEIGHT, WIDTH, OFFSETX, OFFSETY);
	// set_colors_to_players(players_colors, vm->players, vm->players_amnt);
	display_arena(vm, warena);
	// move_ball();
	// del_players_colors(&players_colors, vm->players_amnt);
	getch();
	delwin(warena);
	endwin();
	return (true);
}

