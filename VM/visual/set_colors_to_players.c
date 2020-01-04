/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_colors_to_players.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 21:10:01 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/03 13:50:44 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_visual.h"

void	fill_colors_palette(short color_palette[9])
{
	color_palette[0] = COLOR_RED;
	color_palette[1] = COLOR_YELLOW;
	color_palette[2] = COLOR_GREEN;
	color_palette[3] = INTENSE_PINK;
	color_palette[4] = COLOR_BLUE;
	color_palette[5] = VIOLET;
	color_palette[6] = BRIGHT_YELLOW;
	color_palette[7] = LIGHT_BLUE;
	color_palette[8] = LIGHT_PINK;
}

bool	set_colors_to_players(t_player **players, short players_amnt)
{
	// short	colors_palette[9];
	short	i;

	i = 0;
	// fill_colors_palette(colors_palette);
	while (i < players_amnt)
	{
		players[i]->color = i + 1;//colors_palette[i];
		i++;
	}
	return (true);
}
