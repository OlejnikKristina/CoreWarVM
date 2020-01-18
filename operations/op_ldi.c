/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_ldi.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 16:37:51 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/17 16:19:42 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

/*
		DIR DIR REG (Works) checked
		DIR IND REG (With quations) checked
		REG DIR REG (Works) checked
*/

bool		op_ldi(t_cursor *cursor, t_vm *vm)
{
	e_argctype	args[3];
	int			reg_num;
	int			address;
	int			padding;

	padding = 2;
	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
	address = get_arg_val(args[0], vm->arena, cursor, &padding);
	address += get_arg_val(args[1], vm->arena, cursor, &padding);
	address = (address % IDX_MOD) + cursor->pos % MEM_SIZE;
	reg_num = vm->arena[cursor->pos + padding] - 1;
	cursor->reg[reg_num] = convert(&(vm->arena[address]), 4);
	return (true);
}
