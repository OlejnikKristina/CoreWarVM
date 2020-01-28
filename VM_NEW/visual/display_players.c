/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_players.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 16:24:12 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/28 16:25:06 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visual.h"

void	display_players(t_player **players, WINDOW *winfo, short players_amnt)
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
		"Last time reported \"live\":");
		mvwprintw(winfo, OFFSETY + i * 4 + 2, 4,
		"Reported   \"live\" (times):");
		i++;
	}
	mvwprintw(winfo, OFFSETY + 20, 3,
	"------------------------------------------------");
}
