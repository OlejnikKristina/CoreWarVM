/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   corewar_visual.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 14:19:39 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/17 19:09:30 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# ifndef COREWAR_VISUAL_H
# define COREWAR_VISUAL_H

# define HEIGHT 68
# define WIDTH 194
# define WOPH (HEIGHT / 4 + 4)
# define WOPW (WIDTH / 4)
# define OFFSETX 3
# define OFFSETY 5
# define DELAY 17000
# define INDEX ((HEIGHT - 8) / players_amnt))

# include <ncurses.h>
# include "vm_arena.h"
# include "corewar_vs_colors.h"

typedef struct 		s_cursor t_cursor;
typedef	struct		s_player t_player;
typedef struct		s_vm t_vm;


typedef struct		s_visual
{
	WINDOW			*winfo;
	WINDOW			*warena;
	WINDOW			*wop;
}					t_visual;

bool				visual_corawar(t_vm *vm);
void				init_pairs();
void				fill_colors_palette(short color_palette[9]);
t_player			*get_player_by_id(t_player **players, short player_id,
					short player_amnt);
void				display_info(t_vm *vm, WINDOW *winfo);
int					get_attribute(int i, t_player **players, short players_amnt);

void				display_cursors(WINDOW *warena, t_cursor *cursor,
					uint8_t arena[MEM_SIZE], t_vm *vm);
void				display_current_cycle(WINDOW *winfo, int current_cycle);
void				display_processes(WINDOW *winfo, int processes_num);
void				display_game_params(WINDOW *winfo);
void				refresh_arena(t_vm *vm);
void				visual_sti(WINDOW *warena, uint8_t arena[], short id, int address);
void				display_live_calls(WINDOW *winfo, t_player *palyer);
void				display_live_calls_init(WINDOW *winfo, short player_amnt);
void				get_xy_coordinates(int *x, int *y, int address);
void				add_pause(WINDOW *winfo);
void				refresh_cycle_to_die(WINDOW *winfo, int paddy, int cycle_to_die);
void				show_corpse(short dead_cursor_id, WINDOW *wop);

void				keyboard_madness(WINDOW *warena);

#endif
