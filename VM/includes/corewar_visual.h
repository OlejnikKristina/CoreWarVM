/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   corewar_visual.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 14:19:39 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/29 15:14:59 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VISUAL_H
# define COREWAR_VISUAL_H

# define HEIGHT 68
# define WIDTH 194
# define WOPH (HEIGHT / 4 + 4)
# define WOPW (WIDTH / 4)
# define OFFSETX 3
# define OFFSETY 5
# define DELAY 13000
# define INDEX ((HEIGHT - 8) / players_amnt))

# include <ncurses.h>
# include "vm_arena.h"
# include "corewar_vs_colors.h"

typedef struct s_vm		t_vm;
typedef struct s_champ	t_champ;
typedef struct s_cursor	t_cursor;
typedef struct s_game	t_game;

typedef struct		s_visual
{
	WINDOW			*winfo;
	WINDOW			*warena;
	WINDOW			*wop;
}					t_visual;

bool				visual_corawar(t_vm *vm);
void				init_pairs(void);
int					vget_player_index(t_champ *champs, short id, int players_amnt);
void				init_info_field(t_vm *vm, WINDOW *winfo);
int					get_attribute(int i, t_champ *champs, short players_amnt);
void				display_cursors(WINDOW *warena, t_cursor *cursor,
					uint8_t arena[MEM_SIZE], t_vm *vm);
void				display_current_cycle(WINDOW *winfo, int current_cycle);
void				display_cycle_passed(WINDOW *winfo, int cycle_passed);
void				display_processes(WINDOW *winfo, int processes_num);
void				display_players(t_champ *players, WINDOW *winfo, short pl_amnt);
void				display_game_params(WINDOW *winfo);
void				display_live_calls(WINDOW *winfo, t_champ palyer, int cycle);
void				display_live_calls_init(WINDOW *winfo, short player_amnt);
void				refresh_arena(t_vm *vm);
void				congrats_champion(WINDOW *wop, t_champ champion);
void				visual_store(WINDOW *warena, uint8_t arena[], short id, int address);
void				get_xy_coordinates(int *x, int *y, int address);
void				add_pause(WINDOW *winfo);
void				refresh_cycle_to_die(WINDOW *winfo, int paddy, int cycle_to_die);
void				step_by_step(void);

#endif
