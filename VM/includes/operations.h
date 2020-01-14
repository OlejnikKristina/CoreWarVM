/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/28 15:40:03 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/14 17:06:10 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

#include "vm_arena.h"

typedef struct	s_vm t_vm;
typedef struct	s_cursor t_cursor;
typedef enum	e_argctype e_argctype;

/* Ops with size T_DIR 4 bytes */

#define LIVE 0x01
#define LD 0x02
#define ST 0x03
#define ADD 0x04
#define SUB 0x05
#define AND 0x06
#define OR 0x07
#define XOR 0x08
#define LLD 0x0d
#define AFF 0x10

/* Ops with size T_DIR 2 bytes */

#define ZJMP 0x09
#define LDI 0x0a
#define STI 0x0b
#define FORK 0x0c
#define LLDI 0x0e
#define LFORK 0x0f

bool		op_live(t_cursor *cursor, t_vm *vm);
bool		op_add(t_cursor *cursor, t_vm *vm);
bool		op_aff(t_cursor *cursor, t_vm *vm);
bool		op_and(t_cursor *cursor, t_vm *vm);
bool		op_fork(t_cursor *cursor, t_vm *vm);
bool		op_lfork(t_cursor *cursor, t_vm *vm);
bool		op_st(t_cursor *cursor, t_vm *vm);
bool		op_sti(t_cursor *cursor, t_vm *vm);
bool		op_ld(t_cursor *cursor, t_vm *vm);
bool		op_ldi(t_cursor *cursor, t_vm *vm);
bool		op_lld(t_cursor *cursor, t_vm *vm);
bool		op_lldi(t_cursor *cursor, t_vm *vm);
bool		op_or(t_cursor *cursor, t_vm *vm);
bool		op_xor(t_cursor *cursor, t_vm *vm);
bool		op_sub(t_cursor *cursor, t_vm *vm);
bool		op_zjmp(t_cursor *cursor, t_vm *vm);

int			get_arg_val(e_argctype arg_type, uint8_t arena[MEM_SIZE],
			t_cursor *cursor, int *padding);
void		write_into_memory(int32_t val_to_write, uint8_t *arena, int address);

#endif
