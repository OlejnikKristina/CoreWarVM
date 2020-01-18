/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm_arena.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 15:52:12 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/18 16:15:38 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_ARENA_H
# define VM_ARENA_H

# include <ncurses.h>
# include <fcntl.h>
# include "op.h"
# include "ft_printf.h"
# include "operations.h"
# include "corewar_visual.h"

# define OP_NBR 16
# define DEBUG_MOD 0
# define DEAD -1000


typedef struct s_cursor	t_cursor;
typedef struct s_visual t_visual;
typedef struct s_player t_player;

struct				s_cursor
{
	short			id;
	bool			carry;
	int				opcode;
	int				last_live;
	short			wait_cycles;
	int				pos;
	int				pc;
	int32_t			reg[REG_NUMBER];
	/* For visualisation */
	int				prev_xy[2];
	int				prev_val;
	t_cursor		*next;
};

typedef struct		s_flags
{
	int				dump;
	int				hexdump;
	bool			v;
	short			players_order[MAX_PLAYERS];
}					t_flags;

typedef	struct		s_player
{
	short			id;
	char			*name;
	char			*comment;
	int				code_size;
	uint8_t			*code;
	int				start_pos;
	int				lives;
	int				last_live;
}					t_player;

/*
 ** v  --------------> visualsation
*/

typedef struct		s_vm
{
	int				current_cycle;
	int				cycle_to_die;
	int				nbr_lives;
	int				process;
	int				alive_players_amt;
	short			players_amnt;
	int				last_alive;
	t_player		**players;
	uint8_t			arena[MEM_SIZE];
	t_flags			*flag;
	t_cursor		*cursor;
	t_visual		*v;
}					t_vm;

typedef enum				e_argctype
{
	REG = 1,
	DIR,
	IND
}							e_argctype;


void				test_reg(void);

/*
	***************************** Parsing Arguments ******************************
*/

bool				args_validation(int argc, char **argv, t_flags *flags);
short				check_flag(int argc, char **params, int *num,
					t_flags *flags);
void				add_n_falg(t_flags *flags, int from, int n);
bool				dump64(t_vm *vm);
bool				check_champ_file_name(char *file_name);
bool				check_champion(char *file_name);
short				get_players_amnt(short players_amnt_init);
char				**safe_players_files(char *file);
bool				parse_error();

/*
	****************************** Init Players *********************************
*/

bool				init_players(t_vm *vm);
bool				check_null_byte(const int fd);
bool				get_player_code_size(t_player *player, const int fd);
bool				get_player_exec_code(t_player *player, const int fd);
void				set_player_id(t_player *player,
					short players_order[MAX_PLAYERS], short num,
					short players_amnt);
int					get_player_id(t_player **players, short player_id,
					short player_amnt);
t_cursor			*init_cursor(int id, int pos, int opcode, int encoding_byte);

/*
	****************************** Battlefield **********************************
*/

bool				init_battlefield(t_vm *vm);
bool				init_cursors(t_vm *vm);
int					calculate_program_counter(uint8_t opcode, uint8_t encod_byte);
int					decode_encoding_byte(unsigned char encod_byte,
					e_argctype op_args[3]);
short				add_bytes_to_pc(e_argctype arg_type, uint8_t opcode);
bool				is_encoding_byte(uint8_t opcode);

/*
	********************************* RUN GAME ************************************
*/

bool				start_game(t_vm *vm);
short				execute_cursor(t_cursor *cursor, uint8_t arena[MEM_SIZE], t_vm *vm);
short				execute_operation(t_cursor *cursor, t_vm *vm);
bool				show_arena(t_player **players, short pl_amnt, t_vm *vm);
int					get_waite_cycle(uint8_t opcode);
void				congrats_champion(WINDOW *wop, t_player *champiom);

/*
	****************************** Utilites *************************************
*/

t_player			*get_player_by_id(t_player **players, short player_id,
					short player_amnt);
bool				error_msg(unsigned short erro_num);
void				introduce_champions(t_player **players, short player_amnt, int colour);
void				init_op_encode_validation_arr(bool (*op_encode[17])(e_argctype *));
bool				en_op_code_and_or_xor(e_argctype arg_type[3]);
bool				en_op_code_ldi_lldi(e_argctype arg_type[3]);
bool				en_op_code_ldi(e_argctype arg_type[3]);
bool				en_op_code_aff(e_argctype arg_type[3]);
bool				en_op_code_sti(e_argctype arg_type[3]);
void				vm_free(t_vm **vm);
short				get_dir_size(uint8_t opcode);
int					convert(unsigned char *s, int size);
void				print_arena_pure(unsigned char arena[MEM_SIZE]);

/*
	****************************** Visualisation *******************************
*/

bool				visual_corawar();

#endif
