/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_color_pairs.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 21:10:01 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/28 18:45:47 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_visual.h"

static void	init_players_colors(void)
{
	init_pair(STI_PL1, NICE_PINCK2, COLOR_BLACK);
	init_pair(STI_PL2, COLOR_GREEN, COLOR_BLACK);
	init_pair(STI_PL3, LIGHT_PINK, COLOR_BLACK);
	init_pair(STI_PL4, NORMAL_BLUE, COLOR_BLACK);
	init_pair(STI_PL5, VIOLET, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, DARCK_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, LIGHT_BLUE, COLOR_BLACK);
	init_pair(5, NICE_PINCK, COLOR_BLACK);
	init_pair(10, LIGHT_PINK, NICE_PINCK2);
	init_pair(20, LIGHT_PINK, DARCK_GREEN);
	init_pair(30, LIGHT_PINK, COLOR_YELLOW);
	init_pair(40, LIGHT_PINK, LIGHT_BLUE);
	init_pair(50, LIGHT_PINK, NICE_PINCK);
}

void		init_pairs(void)
{
	if (!has_colors())
	{
		endwin();
		ft_printf("Your terminal does't support colors\n");
	}
	start_color();
	init_pair(WHITE_BLACK, COLOR_WHITE, COLOR_BLACK);
	init_pair(PINK_YELLOW, NICE_PINCK2, COLOR_YELLOW);
	init_pair(YELLOW_PINK, COLOR_YELLOW, NICE_PINCK2);
	init_pair(PINK_BLACK, NICE_PINCK2, COLOR_BLACK);
	init_pair(PINK_BLUE, LIGHT_BLUE, NICE_PINCK);
	init_pair(LBLUE_BLACK, LIGHT_BLUE, COLOR_BLACK);
	init_players_colors();
}
