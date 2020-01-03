/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_info.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 15:07:32 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/03 15:23:24 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_visual.h"

void 		display_players(t_player **players, WINDOW *winfo, short players_amnt)
{
	short		i;
	int			attribute;
	t_player	*player;

	i = 0;
	wmove(winfo, OFFSETY + 5, 2);
	while (i < players_amnt)
	{
		player = get_player_by_id(players, i + 1, players_amnt);
		attribute = get_attribute(i, players, players_amnt);
		wattron(winfo, attribute);
		wprintw(winfo, "PLAYER %d", (int)i + 1);
		wprintw(winfo, player->name);
		i++;
	}
}

void		display_info(t_vm *vm, WINDOW *winfo)
{
	display_players(vm->players, winfo, vm->players_amnt);
}
