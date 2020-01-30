/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_lldi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 20:34:40 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/30 21:31:18 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

bool		op_lldi(t_cursor *cursor, t_vm *vm)
{
	e_argctype	args[3];
	int			reg_num;
	int			address;
	int			padding;

	padding = 2;
	decode_encoding_byte(vm->arena[(cursor->pos + 1) % MEM_SIZE], args);
	address = get_arg_val(args[0], vm->arena, cursor, &padding);
	address += get_arg_val(args[1], vm->arena, cursor, &padding);
	address += cursor->pos;
	while (MEM_SIZE <= address)
		address -= MEM_SIZE;
	reg_num = vm->arena[(cursor->pos + padding) % MEM_SIZE] - 1;
	cursor->reg[reg_num] = convert(&(vm->arena[address]), 4);
	cursor->carry = (cursor->reg[reg_num] == 0 ? 1 : 0);
	return (true);
}
