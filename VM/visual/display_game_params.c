/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_game_params.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:45:10 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/28 16:48:21 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visual.h"

void		refresh_cycle_to_die(WINDOW *winfo, int paddy, int cycle_to_die)
{
	wattron(winfo, COLOR_PAIR(YELLOW_PINK) | A_BOLD);
	mvwprintw(winfo, paddy + 30, 19, "[%d]", cycle_to_die);
	wattroff(winfo, COLOR_PAIR(YELLOW_PINK) | A_BOLD);
}

static void	game_params_lables(WINDOW *winfo, int paddy)
{
	char	spaces[26];

	ft_memset((void *)spaces, ' ', 26);
	spaces[25] = '\0';
	spaces[0] = '|';
	spaces[24] = '|';
	wattron(winfo, COLOR_PAIR(PINK_YELLOW) | A_BOLD);
	mvwprintw(winfo, paddy + 30, 3, "| Cycle to Die: ");
	mvwprintw(winfo, paddy + 32, 3, "| Cycle  Delta: ");
	mvwprintw(winfo, paddy + 34, 3, "| Number Lives: ");
	mvwprintw(winfo, paddy + 36, 3, "| Max   Checks: ");
	mvwprintw(winfo, paddy + 30, 24, "   |");
	mvwprintw(winfo, paddy + 32, 23, "    |");
	mvwprintw(winfo, paddy + 34, 23, "    |");
	mvwprintw(winfo, paddy + 36, 22, "     |");
	mvwprintw(winfo, paddy + 29, 3, "-------------------------");
	mvwprintw(winfo, paddy + 31, 3, "%s", spaces);
	mvwprintw(winfo, paddy + 33, 3, "%s", spaces);
	mvwprintw(winfo, paddy + 35, 3, "%s", spaces);
	mvwprintw(winfo, paddy + 37, 3, "-------------------------");
}

static void	game_params_constans(WINDOW *winfo, int paddy)
{
	wattron(winfo, COLOR_PAIR(YELLOW_PINK) | A_BOLD);
	mvwprintw(winfo, paddy + 30, 19, "[%d]", CYCLE_TO_DIE);
	mvwprintw(winfo, paddy + 32, 19, "[%d]", CYCLE_DELTA);
	mvwprintw(winfo, paddy + 34, 19, "[%d]", NBR_LIVE);
	mvwprintw(winfo, paddy + 36, 19, "[%d]", MAX_CHECKS);
	wattroff(winfo, COLOR_PAIR(YELLOW_PINK) | A_BOLD);
}

void		display_game_params(WINDOW *winfo)
{
	game_params_lables(winfo, 29);
	game_params_constans(winfo, 29);
}
