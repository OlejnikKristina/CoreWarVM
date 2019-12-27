/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm_arena.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 15:52:12 by krioliin       #+#    #+#                */
/*   Updated: 2019/12/27 16:03:35 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_ARENA_H
# define VM_ARENA_H

#include <fcntl.h>
#include "op.h"
#include "../ft_printf/includes/ft_printf.h"
// #include "ft_printf.h"

/*
*** v								visualisation
*/

typedef struct		s_cursor	t_cursor;

struct				t_cursor
{
	short			colour;
	short			id;
	bool			carry;
	short			opcode;
	short			last_live;
	short			wait_cycles;
	uint8_t			pos;
	int				jump;
	uint8_t			reg[REG_NUMBER];
	t_cursor		*next;
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
	uint8_t			code_size;
	uint8_t			*code;
}					t_player;

typedef struct		s_vm
{
	short			players_amnt;
	t_player		**players;
	uint8_t			arena[MEM_SIZE];
	t_flags			*flag;
	t_cursor		*cursor;
}					t_vm;

/*************************** Parsing Arguments *******************************/

bool				args_validation(int argc, char **argv, t_flags *flags);
short				check_flag(int argc, char **params, int *num, t_flags *flags);
void				add_n_falg(t_flags *flags, int from, int n);
bool				check_champ_file_name(char *file_name);
bool				check_champion(char *file_name);
short				get_players_amnt(short players_amnt_init);
char				**safe_players_files(char *file);
bool				parse_error();

/******************************* Init Players ********************************/

bool				init_players(t_vm *vm);
bool				check_null_byte(const int fd);
bool				get_player_code_size(t_player *player, const int fd);
void				set_player_id(t_player *player, short players_order[MAX_PLAYERS],
					short num);

/******************************* Utilites ********************************/

bool				error_msg(unsigned short erro_num);
void				vm_free(t_vm **vm);

#endif
