/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm_arena.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:25:13 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/26 18:43:37 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_ARENA_H
# define VM_ARENA_H

# include <ncurses.h>
# include <fcntl.h>
# include <stdlib.h>
# include "op.h"
# include "../ft_printf/includes/ft_printf.h"
# include "operations.h"
// # include "corewar_visual.h"

# define OP_NBR 16
# define DEBUG_MOD 0
# define NB_OPS 0x10
# define NB_PLAYERS vm->nb_players
# define CHAMPS vm->champs
# define ARENA vm->arena
# define GAME vm->game
# define CURSORS GAME->cursors
# define FLAG vm->flag

typedef struct s_vm t_vm;
typedef struct s_flags t_flags;
typedef struct s_args t_args;
typedef struct s_champ t_champ;
typedef struct s_cursor t_cursor;
typedef struct s_game t_game;
typedef struct s_files t_files;


/*
**	@desc	- struct that holds cursors in a linked list
**	@param	- long id,
**			- int moved, 1 or 0, to know if it moved recently
**			- int carry, 1 or 0, carry for ZJMP
**			- int opcode, current operationcode 
**			- int last_live, last live call of cursor
**			- int wait_cycles, total amont of waitcycles for this operation
**			- int pos, current position of the cursor
**			- int pc, amount of bytes needed to jump to next operation
**			- int reg[REG_NUMBER], registries for this cursor
**			- t_cursor *next, next cursor (if any)
*/

struct			s_cursor
{
	long		id;
	int			moved;
	int			carry;
	int			opcode;
	int			last_live;
	int			wait_cycles;
	int			pos;
	int			pc;
	int			reg[REG_NUMBER];
	t_cursor	*next;
	/* For visualisation */
	int			prev_xy[2];
	int			prev_val;
};

/*
**	@desc	- struct holds info for all champs
**	@param	- int id, unique id of player
**			- int size, size of the exec code
**			- char *name, name of the champ
**			- char *comment, comment of the champ
**			- int lives, amount of live calls
**			- int last_live, last live call (nb_cycle)
**			- int start_pos, starting position of player
**			- int code, exec code of the player
*/

struct		s_champ
{
	int		id;
	int		size;
	char	*name;
	char	*comment;
	int		lives;
	int		last_live;
	int		start_pos;
};

/*
**	@desc	- struct for the option flags
**	@param	- int dump, sets the cycles for the dump flag
**			- int v, 1 or 0 for visualizer
**			- short player_order[MAX_PLAYERS], stores the player order for
**			the -n flag
*/

struct		s_flags
{
	int		dump;
	int		v;
	short	play_order[MAX_PLAYERS];
};

/*
**	@desc	- struct for the arguments of operations
**	@param	- int value, stores value of the argument
**			- int size, stores size of the argument
**			- int type, flag for type of argument
*/

struct		s_args
{
	int		value;
	int		size;
	int		type;
};

/*
**	@desc	- struct that holds all data of the game
**	@param	- int winner, id of the winner
**			- int cycles, current nb of cycles
**			- int lives, amount of live calls
**			- int processes, amount of processes running
**			- int cycles_to_die, cycles till next check
**			- int checks, nb of checks performed
**			- t_cursor *cursors, linked list of cursors in the game
*/

struct			s_game
{
	int			winner;
	int			cycles;
	int			lives;
	int			processes;
	int			cycles_to_die;
	int			checks;
	long		cursors_id;
	t_cursor	*cursors;
};

/*
**	@desc	- main struct of the VM
**	@param	- short nb_players, total number of players
**			- t_byte arena[MEM_SIZE], arena the game takes place,
**			MEM_SIZE is define
**			- t_flags *flag, struct stores the flags
**			- t_champs *champ, champions
*/

struct		s_vm
{
	short	nb_players;
	int		champ_id;
	t_byte	arena[MEM_SIZE];
	t_flags	*flag;
	t_champ	*champs;
	t_game	*game;
};

/*
********************************* UTILS *********************************
*/
void		error(char *message, char *file);
int			swap_32(int nb);
int			arg_size(int type, int opcode);
int			dump64(t_vm *vm);
int			wait_cycle(int opcode);
void		put_value(t_byte *arena, int index, void *val);
int			get_player(t_vm *vm, t_champ *champs, int id);
int			format_check(char *format, char *s);
int			get_index(int current, int move);
int			get_bytes(t_byte *arena, int idx, int amount);

/*
******************************** PARSING ********************************
*/
void		parse(t_vm *vm, int ac, char **av);
int			check_name(char *name);
int			check_file(char *name);
void		flags(t_vm *vm, int ac, char **av);
void		get_champs(t_vm *vm, char **av, int ac);
int			get_champ_comment(t_champ *champ, const int fd);
int			get_champ_name(t_champ *champ, const int fd);
int			check_code(t_vm *vm, t_champ *c, t_byte *code/*, int size*/);

/*
********************************* INIT **********************************
*/
void		init_game(t_vm *vm);
void		swap_champs(t_champ *champs, int nb_champs);
t_cursor	*cp_cursor(t_cursor *src, int pos, long id);
void		mv_cursor(t_vm *vm, t_cursor *c, int move);
void		add_cursor(t_cursor **head, t_cursor *new);
t_cursor	*rm_cursor(t_cursor *head, long id);
t_cursor	*new_cursor(int position, int r1, long id);

/*
********************************* GAME **********************************
*/
void		start_game(t_vm *vm);
void		execute(t_vm *vm);
t_args  	*get_args(t_cursor *c, t_byte octal, t_byte *arena);
void		do_op(t_vm *vm, t_cursor *c, t_args *args, int size);
void		opcode(t_byte opcode, t_cursor *c);
#endif