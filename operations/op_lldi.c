/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_lldi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 20:34:40 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/11 15:53:35 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
		DIR DIR REG (Works) checked
		DIR IND REG (Works With questions) checked
		REG DIR REG (Works 100%) checked
*/

#include "vm_arena.h"

bool		op_lldi(t_cursor *cursor, t_vm *vm)
{
	e_argctype	args[3];
	int			reg_num;
	int			address;
	int			padding;

	padding = 2;
	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
	address = get_arg_val(args[0], vm->arena, cursor, &padding);
	address += get_arg_val(args[1], vm->arena, cursor, &padding);
	address += cursor->pos % MEM_SIZE;
	reg_num = vm->arena[cursor->pos + padding] - 1;
	cursor->reg[reg_num] = convert(&(vm->arena[address]), 4);
	return (true);
}
