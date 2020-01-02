/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   corewar_visual.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 14:19:39 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/02 21:17:19 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VISUAL_H
# define COREWAR_VISUAL_H

# define HEIGHT 66 + 8
# define WIDTH 194 + 4
# define OFFSETX 3
# define OFFSETY 5

# include <ncurses.h>
# include "vm_arena.h"
# include "corewar_vs_colors.h"

typedef struct		s_player_color
{
	short			id;
	short			color;
}					t_pl_color;


bool				visual_corawar(t_vm *vm);
void				fill_colors_palette(short color_palette[9]);
bool				set_colors_to_players(t_pl_color **pl_colors, t_player **players,
					short players_amnt);
t_player			*get_player(t_player **players, short player_id, short player_amnt);

#endif
