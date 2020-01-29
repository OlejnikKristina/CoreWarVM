/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/28 15:40:03 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/28 16:42:53 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "vm_arena.h"

typedef struct s_vm		t_vm;
typedef struct s_cursor	t_cursor;
typedef struct s_args	t_args;

/*
** Ops with size T_DIR 4 bytes
*/

# define LIVE 0x01
# define LD 0x02
# define ST 0x03
# define ADD 0x04
# define SUB 0x05
# define AND 0x06
# define OR 0x07
# define XOR 0x08
# define LLD 0x0d
# define AFF 0x10

/*
** Ops with size T_DIR 2 bytes
*/

# define ZJMP 0x09
# define LDI 0x0a
# define STI 0x0b
# define FORK 0x0c
# define LLDI 0x0e
# define LFORK 0x0f

void	live(t_vm *vm, t_cursor *c, t_args *args);
void	ld(t_vm *vm, t_cursor *c, t_args *args);
void	st(t_vm *vm, t_cursor *c, t_args *args);
void	add(t_cursor *c, t_args *args);
void	sub(t_cursor *c, t_args *args);
void	and(t_vm *vm, t_cursor *c, t_args *args);
void	or(t_vm *vm, t_cursor *c, t_args *args);
void	xor(t_vm *vm, t_cursor *c, t_args *args);
void	zjmp(t_vm *vm, t_cursor *c, t_args *args);
void	ldi(t_vm *vm, t_cursor *c, t_args *args);
void	sti(t_vm *vm, t_cursor *c, t_args *args);
void	op_fork(t_vm *vm, t_cursor *c, t_args *args, int mod);
void	lld(t_vm *vm, t_cursor *c, t_args *args);
void	lldi(t_vm *vm, t_cursor *c, t_args *args);
void	aff(t_cursor *c, t_args *args);

#endif
