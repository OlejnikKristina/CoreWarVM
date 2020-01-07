/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_operation.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 15:19:29 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/07 16:56:53 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"
#include "operations.h"

short	execute_operation(t_cursor *cursor, t_vm *vm)
{
	if (
	(cursor->opcode == LIVE && op_live(cursor, vm)) ||
	(cursor->opcode == LD && op_ld(cursor, vm)) ||
	(cursor->opcode == ST && op_st(cursor, vm)) ||
	(cursor->opcode == ADD && op_add(cursor, vm)) ||
	(cursor->opcode == SUB && op_sub(cursor, vm)) ||
	(cursor->opcode == AND && op_and(cursor, vm)) ||
	(cursor->opcode == OR && op_or(cursor, vm)) ||
	(cursor->opcode == XOR && op_xor(cursor, vm)) ||
	(cursor->opcode == ZJMP && op_zjmp(cursor, vm)) ||
	(cursor->opcode == LDI && op_ldi(cursor, vm)) ||
	(cursor->opcode == STI && op_sti(cursor, vm)) ||
	(cursor->opcode == FORK && op_fork(cursor, vm)) ||
	(cursor->opcode == LLD && op_lld(cursor, vm)) ||
	(cursor->opcode == LLDI && op_lldi(cursor, vm)) ||
	(cursor->opcode == LFORK && op_lfork(cursor, vm)) ||
	(cursor->opcode == AFF && op_aff(cursor, vm)))
		;
	return (0);
}