/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm_arena.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 15:52:12 by krioliin       #+#    #+#                */
/*   Updated: 2019/12/22 19:09:56 by krioliin      ########   odam.nl         */
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

typedef struct		s_flags
{
	int				dump;
	bool			v;
	short			players_order[MAX_PLAYERS];
}					t_flags;

typedef	struct		s_player
{
	short			id;
	// char			*name;
	// char			*credo;
	t_header		header;
	uint8_t			*code;
}					t_player;

typedef struct		s_vm
{
	short			players_amnt;
	t_player		**players;
	uint8_t			arena[MEM_SIZE];
	t_flags			*flag;
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

/******************************* Utilites ********************************/

void				vm_free(t_vm **vm);

#endif
