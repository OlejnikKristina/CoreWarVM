/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_windows.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 15:26:21 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/29 14:37:23 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visual.h"

int				get_attribute(int i, t_champ *players, short players_amnt)
{
	static int		prev_code_size;
	static short	player_id;
	int				index;
	int				x;

	if (i == 0)
	{
		player_id = 0;
		i = 0;
	}
	index = (MEM_SIZE / players_amnt) * player_id;
	x = vget_player_index(players, player_id + 1, players_amnt);
	if (i - index >= players[x].size)
	{
		prev_code_size = players[x].size + index;
		player_id++;
	}
	else if (prev_code_size < i && i < index)
		return (COLOR_PAIR(5) | A_BOLD);
	else if (i - index < players[x].size && prev_code_size <= i)
		return (COLOR_PAIR(player_id + 1) | A_BOLD);
	return (COLOR_PAIR(5) | A_BOLD);
}

static void		display_arena(t_vm *vm, WINDOW *warena)
{
	int		yx[2];
	int		i;
	int		attribute;
	short	num;

	i = 0;
	yx[0] = 1;
	num = 0;
	wmove(warena, OFFSETY + 1, 0);
	while (i < MEM_SIZE - 1)
	{
		yx[1] = 0;
		while (yx[1] < 64 * 3)
		{
			attribute = get_attribute(i, vm->champs, vm->nb_players);
			wattron(warena, attribute);
			yx[1] += 3;
			mvwprintw(warena, OFFSETY + yx[0], yx[1], "%.2x ", vm->arena[i]);
			i++;
		}
		yx[0] += 1;
		wprintw(warena, " ");
	}
	wrefresh(warena);
}

static WINDOW	*init_arena(int height, int width, int startx, int starty)
{
	WINDOW	*warena;

	wbkgd(stdscr, COLOR_PAIR(WHITE_BLACK) | A_BOLD);
	refresh();
	warena = newwin(height, width, startx, starty);
	wbkgd(warena, COLOR_PAIR(WHITE_BLACK) | A_BOLD);
	wborder(warena, '|', '|', '*', '*', '*', '*', '*', '*');
	mvaddstr(OFFSETY + 3, OFFSETX + ((width / 2) - 12),
	"C O R E  W A R");
	wrefresh(warena);
	return (warena);
}

static WINDOW	*init_winfo(int height, int width, int startx, int starty)
{
	WINDOW *winfo;

	winfo = newwin(height, width, startx, starty + 3);
	wbkgd(winfo, COLOR_PAIR(WHITE_BLACK) | A_BOLD);
	wborder(winfo, '|', '|', '*', '*', '*', '*', '*', '*');
	wrefresh(winfo);
	return (winfo);
}

bool			visual_corawar(t_vm *vm)
{
	initscr();
	nodelay(stdscr, true);
	curs_set(0);
	init_pairs();
	if (!(vm->v = (t_visual *)ft_memalloc(sizeof(t_visual))))
		return (false);
	vm->v->warena =
	init_arena(HEIGHT + OFFSETY, WIDTH + OFFSETX + 1, OFFSETY, OFFSETX);
	vm->v->winfo =
	init_winfo(HEIGHT + OFFSETY, (WIDTH) / 4 + 7, OFFSETY, WIDTH + OFFSETX);
	display_arena(vm, vm->v->warena);
	init_info_field(vm, vm->v->winfo);
	return (true);
}
