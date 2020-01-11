/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   corewar_visual.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 14:19:39 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/11 19:21:05 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VISUAL_H
# define COREWAR_VISUAL_H

# define HEIGHT (66 + 8)
# define WIDTH (194 + 4)
# define OFFSETX 3
# define OFFSETY 5
# define DELAY 30000

# include <ncurses.h>
# include "vm_arena.h"
# include "corewar_vs_colors.h"

typedef	struct		s_player t_player;
typedef struct		s_vm t_vm;

typedef struct		s_visual
{
	WINDOW			*winfo;
	WINDOW			*warena;
}					t_visual;

bool				visual_corawar(t_vm *vm);
void				init_pairs();
void				fill_colors_palette(short color_palette[9]);
bool				set_colors_to_players(t_player **players, short players_amnt);
t_player			*get_player_by_id(t_player **players, short player_id,
					short player_amnt);
void				display_info(t_vm *vm, WINDOW *winfo);
int					get_attribute(int i, t_player **players, short players_amnt);

void				display_cursors(WINDOW *warena, t_cursor *cursor,
					uint8_t arena[MEM_SIZE], short players_amnt);
void				display_current_cycle(WINDOW *winfo, int current_cycle);
void				display_processes(WINDOW *winfo, int processes_num);
void				refresh_arena(t_vm *vm);

#endif
