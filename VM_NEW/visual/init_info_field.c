/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_info_field.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 15:07:32 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/29 13:05:02 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visual.h"

static void	display_labels(WINDOW *winfo)
{
	wattron(winfo, COLOR_PAIR(PINK_BLACK) | A_BOLD);
	mvwprintw(winfo, OFFSETY + 25, 3, "Current cycle:");
	mvwprintw(winfo, OFFSETY + 27, 3, "Cycles passed:");
	mvwprintw(winfo, OFFSETY + 29, 3, "Processes:");
}

void		display_current_cycle(WINDOW *winfo, int current_cycle)
{
	wattron(winfo, COLOR_PAIR(LBLUE_BLACK) | A_BOLD);
	mvwprintw(winfo, OFFSETY + 25, 21, " %.5d", current_cycle);
	wattroff(winfo, COLOR_PAIR(LBLUE_BLACK) | A_BOLD);
}

void		display_cycle_passed(WINDOW *winfo, int cycle_passed)
{
	wattron(winfo, COLOR_PAIR(LBLUE_BLACK) | A_BOLD);
	mvwprintw(winfo, OFFSETY + 27, 22, "%u", cycle_passed);
	wattroff(winfo, COLOR_PAIR(LBLUE_BLACK) | A_BOLD);
}

void		display_processes(WINDOW *winfo, int processes_num)
{
	wattron(winfo, COLOR_PAIR(LBLUE_BLACK) | A_BOLD);
	mvwprintw(winfo, OFFSETY + 29, 22, "%.5d", processes_num);
	wattroff(winfo, COLOR_PAIR(LBLUE_BLACK) | A_BOLD);
}

void		init_info_field(t_vm *vm, WINDOW *winfo)
{
	wmove(winfo, (OFFSETY / 2) + 2, 4);
	wattron(winfo, COLOR_PAIR(WHITE_BLACK) | A_BOLD);
	display_players(vm->champs, winfo, vm->nb_players);
	mvwprintw(winfo, OFFSETY + 22, 3,
	" ** ***** G A M E  P A R A M E T E R S ***** ** ");
	display_labels(winfo);
	display_current_cycle(winfo, 0);
	display_processes(winfo, 0);
	display_game_params(winfo);
	display_current_cycle(vm->v->winfo, 1);
	display_cycle_passed(vm->v->winfo, 1);
	display_processes(vm->v->winfo, 1);
	display_live_calls_init(vm->v->winfo, vm->nb_players);
	wrefresh(winfo);
}
