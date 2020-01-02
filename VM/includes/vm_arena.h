/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm_arena.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 15:52:12 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/02 14:07:31 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_ARENA_H
# define VM_ARENA_H

# include <fcntl.h>
# include "op.h"
# include "ft_printf.h"

typedef struct s_cursor	t_cursor;

struct				s_cursor
{
	short			id;
	short			color;
	bool			carry;
	short			opcode;
	short			last_live;
	short			wait_cycles;
	uint8_t			position;
	int				program_counter;
	uint8_t			reg[REG_NUMBER][REG_SIZE];
	t_cursor		*next;
	t_cursor		*prev;
};

typedef struct		s_flags
{
	int				dump;
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
}					t_player;

typedef struct		s_vm
{
	short			players_amnt;
	t_player		**players;
	uint8_t			arena[MEM_SIZE];
	t_flags			*flag;
	t_cursor		*cursor;
}					t_vm;

typedef enum				e_argctype
{
	REG = 1,
	DIR,
	IND
}							e_argctype;


void				test_reg(void);

/*
	***************************** Parsing Arguments ****************************
*/

bool				args_validation(int argc, char **argv, t_flags *flags);
short				check_flag(int argc, char **params, int *num,
					t_flags *flags);
void				add_n_falg(t_flags *flags, int from, int n);
bool				check_champ_file_name(char *file_name);
bool				check_champion(char *file_name);
short				get_players_amnt(short players_amnt_init);
char				**safe_players_files(char *file);
bool				parse_error();

/*
	****************************** Init Players ******************************
*/

bool				init_players(t_vm *vm);
bool				check_null_byte(const int fd);
bool				get_player_code_size(t_player *player, const int fd);
bool				get_player_exec_code(t_player *player, const int fd);
void				set_player_id(t_player *player,
short players_order[MAX_PLAYERS], short num, short players_amnt);

/*
	****************************** Battlefield *******************************
*/

bool				init_battlefield(t_vm *vm);
int					calculate_program_counter(uint8_t opcode, uint8_t encod_byte);
int					decode_encoding_byte(unsigned char encod_byte, e_argctype op_args[3]);
short				add_bytes_to_pc(e_argctype arg_type, uint8_t opcode);
bool				is_encoding_byte(uint8_t opcode);


/*
	****************************** Utilites *******************************
*/

bool				error_msg(unsigned short erro_num);
void				introduce_champions(t_player **players, short player_amnt);
void				vm_free(t_vm **vm);

/*
	****************************** Visualisation *******************************
*/

bool				visual_corawar();

#endif
