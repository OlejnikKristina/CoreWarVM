/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   corewar_visual.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 15:26:21 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/04 16:11:18 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_visual.h"

void	init_pairs()
{
	if (!has_colors())
	{
		endwin();
		ft_printf("Your terminal does't support colors\n");
	}
	start_color();
	init_pair(BGRED_FBLACK, COLOR_RED, COLOR_BLACK);
	init_pair(BGYELLOW_FBLACK, BRIGHT_YELLOW, COLOR_BLACK);
	init_pair(WHITE_BLACK, COLOR_WHITE, COLOR_BLACK);
	init_pair(PINK_YELLOW, NICE_PINCK2, COLOR_YELLOW);
	init_pair(YELLOW_PINK, COLOR_YELLOW, NICE_PINCK2);
	init_pair(PINK_BLACK, NICE_PINCK2, COLOR_BLACK);
	init_pair(LBLUE_BLACK, LIGHT_BLUE, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, DARCK_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, LIGHT_BLUE, COLOR_BLACK);
	init_pair(5, NICE_PINCK, COLOR_BLACK);
}

int			get_attribute(int i, t_player **players, short players_amnt)
{
	static int		prev_code_size;
	static short	player_id;
	int				index;
	t_player		*player;

	if (i == 0)
	{
		player_id = 0;
		i = 0;
	}
	index = (MEM_SIZE / players_amnt) * player_id;
	if (!(player = get_player_by_id(players, player_id + 1, players_amnt)))
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

WINDOW	*init_arena(int	height, int width, int startx, int starty)
{
	WINDOW	*warena;

	wbkgd(stdscr, COLOR_PAIR(WHITE_BLACK) | A_BOLD);
	refresh();

	warena = newwin(height, width, startx, starty);
	wbkgd(warena, COLOR_PAIR(WHITE_BLACK) | A_BOLD);
	wborder(warena, '|', '|', '*','*','*', '*', '*', '*');
	mvaddstr(OFFSETY + 3, OFFSETX + ((width / 2) - 12),
	"C O R E  W A R");
	wrefresh(warena);
	return (warena);
}

WINDOW	*init_winfo(int	height, int width, int startx, int starty)
{
	WINDOW *winfo;

	winfo = newwin(height, width, startx, starty);
	wbkgd(winfo, COLOR_PAIR(WHITE_BLACK) | A_BOLD);
	wborder(winfo, '|', '|', '*','*', '*', '*', '*', '*');
	wrefresh(winfo);
	refresh();
	return (winfo);
}

bool	visual_corawar(t_vm *vm)
{
	WINDOW		*warena;
	WINDOW		*winfo;

	initscr();
	init_pairs();
	warena = init_arena(HEIGHT, WIDTH, OFFSETY, OFFSETX);
	winfo = init_winfo(HEIGHT, (WIDTH) / 4 + 7, OFFSETY, WIDTH + 3);
	display_arena(vm, warena);
	display_info(vm, winfo);
	set_colors_to_players(vm->players, vm->players_amnt);
	
	getch();
	delwin(warena);
	delwin(winfo);
	endwin();
	return (true);
}

