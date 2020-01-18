/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_info.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 15:07:32 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/17 15:57:56 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_visual.h"

void		display_current_cycle(WINDOW *winfo, int current_cycle)
{
	static	bool lable_set;

	if (lable_set == false)
	{
		wattron(winfo, COLOR_PAIR(PINK_BLACK) | A_BOLD);
		mvwprintw(winfo, OFFSETY + 25, 3, "Current cycle:");
		lable_set = true;
	}
	wattron(winfo, COLOR_PAIR(LBLUE_BLACK) | A_BOLD);
	mvwprintw(winfo, OFFSETY + 25, 21, " %.5d", current_cycle);
	wattroff(winfo, COLOR_PAIR(LBLUE_BLACK) | A_BOLD);
}

void		display_processes(WINDOW *winfo, int processes_num)
{
	static	bool lable_set;

	if (lable_set == false)
	{
		wattron(winfo, COLOR_PAIR(PINK_BLACK) | A_BOLD);
		mvwprintw(winfo, OFFSETY + 27, 3, "Processes:");
		lable_set = true;
	}
	wattron(winfo, COLOR_PAIR(LBLUE_BLACK) | A_BOLD);
	mvwprintw(winfo, OFFSETY + 27, 22, "%.5d", processes_num);
	wattroff(winfo, COLOR_PAIR(LBLUE_BLACK) | A_BOLD);
}

void		display_players(t_player **players, WINDOW *winfo, short players_amnt)
{
	short		i;
	t_player	*player;

	i = 1;
	wprintw(winfo, " ** ******* C H A M P I O N S ******* ** ");
	mvwprintw(winfo, OFFSETY + 1, 3,
	"------------------------------------------------");
	wmove(winfo, OFFSETY + 4, 4);
	while (i <= players_amnt)
	{
		player = get_player_by_id(players, i, players_amnt);
		wattron(winfo, COLOR_PAIR(i) | A_BOLD);
		mvwprintw(winfo, OFFSETY + i * 4, 4, "PLAYER %d:  ", (int)i);
		mvwprintw(winfo, OFFSETY + i * 4, 15, player->name);
		wattroff(winfo, COLOR_PAIR(i) | A_BOLD);
		mvwprintw(winfo, OFFSETY + i * 4 + 1, 4,
		"Reported   \"live\" (times):");
		mvwprintw(winfo, OFFSETY + i * 4 + 2, 4,
		"Last time reported \"live\":");
		i++;
	}
	mvwprintw(winfo, OFFSETY + 20, 3,
	"------------------------------------------------");
}

void		display_info(t_vm *vm, WINDOW *winfo)
{
	wmove(winfo, (OFFSETY / 2) + 2, 4);
	wattron(winfo, COLOR_PAIR(WHITE_BLACK) | A_BOLD);
	display_players(vm->players, winfo, vm->players_amnt);
	mvwprintw(winfo, OFFSETY + 22, 3,
	" ** ***** G A M E  P A R A M E T E R S ***** ** ");
	display_current_cycle(winfo, 0);
	display_processes(winfo, 0);
	display_game_params(winfo);
	display_current_cycle(vm->v->winfo, 1);
	display_processes(vm->v->winfo, 1);
	display_live_calls_init(vm->v->winfo, vm->players_amnt);
	wrefresh(winfo);
}
