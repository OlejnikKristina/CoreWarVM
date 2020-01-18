/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   corewar_visual.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 15:26:21 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/16 21:52:34 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_visual.h"

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
	wmove(warena, OFFSETY + 1, 0);
	while (i < MEM_SIZE - 1)
	{
		yx[1] = 0;
		while (yx[1] < 64 * 3)
		{
			attribute = get_attribute(i, vm->players, vm->players_amnt);
			wattron(warena, attribute);
			mvwprintw(warena, OFFSETY + yx[0], yx[1] + 3, "%.2x ", vm->arena[i]);
			i++;
			yx[1] += 3;
		}
		yx[0] += 1;
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
	return (winfo);
}

WINDOW *init_woperations(int height, int width, int startx, int starty)
{
	WINDOW *wop;

	wop = newwin(height, width, startx, starty);
	wbkgd(wop, COLOR_PAIR(WHITE_BLACK) | A_BOLD);
	wrefresh(wop);
	return(wop);
}

bool	visual_corawar(t_vm *vm)
{
	initscr();
	// noecho();
	nodelay(stdscr, true);
	curs_set(0);
	init_pairs();
	vm->v = (t_visual *)ft_memalloc(sizeof(t_visual));
	if (!vm)
		return (false);
	vm->v->warena = init_arena(HEIGHT + OFFSETY, WIDTH + OFFSETX + 1, OFFSETY, OFFSETX);
	vm->v->winfo = init_winfo(HEIGHT + OFFSETY, (WIDTH) / 4 + 7, OFFSETY, WIDTH + OFFSETX + 3);
	vm->v->wop = init_woperations(WOPH, WOPW, HEIGHT / 2 + 6, WIDTH + 9);
	// keyboard_madness(vm->v->warena);
	display_arena(vm, vm->v->warena);
	display_info(vm, vm->v->winfo);
	return (true);
}

