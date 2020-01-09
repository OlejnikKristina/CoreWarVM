/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_sti.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 18:04:40 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/09 18:19:55 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "vm_arena.h"

void		write_into_memory(int32_t val_to_write, uint8_t arena[])
{
	uint8_t		*pointer;

	pointer = (uint8_t *)&val_to_write;
	arena[0] = pointer[0];
	arena[1] = pointer[1];
	arena[2] = pointer[2];
	arena[3] = pointer[3];
}

int			get_argc_val(e_argctype arg_type, uint8_t arena[MEM_SIZE],
			t_cursor *cursor, int *padding)
{
	int val;
	int reg_num;

	val = 0;
	if (arg_type == REG)
	{
		reg_num = arena[cursor->pos + 3 + *padding] - REG;
		val = cursor->reg[reg_num];
		*padding = REG;
	}
	else if (arg_type == DIR)
	{
		val = arena[cursor->pos + 4 + *padding];
		*padding = 2;
	}
	else if (arg_type == IND)
	{
		val = arena[convert(&arena[cursor->pos + 2 + *padding], 4) % IDX_MOD];
		*padding = 2;
	}
	return (val);
}

bool		op_sti(t_cursor *cursor, t_vm *vm)
{
	e_argctype	args[3];
	int32_t		val;
	int			address;
	int			reg_num;
	int			padding;

	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
	val = cursor->reg[vm->arena[cursor->pos + 2] - REG];
	address = 0;
	if (args[1] == REG)
	{
		reg_num = vm->arena[cursor->pos + 3] - REG;
		address = cursor->reg[reg_num];
		padding = REG;
	}
	else if (args[1] == DIR)
	{
		address = vm->arena[cursor->pos + 4];
		padding = 2;
	}
	else if (args[1] == IND)
	{
		address = vm->arena[convert(&vm->arena[cursor->pos + 2], 4) % IDX_MOD];
		padding = 2;
	}
	if (args[2] == REG)
	{
		reg_num = vm->arena[cursor->pos + 2 + padding];
		address += cursor->reg[reg_num]; 
	}
	else if (args[2] == DIR)
	{
		address += vm->arena[cursor->pos + 4 + padding];
	}
	address %= IDX_MOD + cursor->pos;
	write_into_memory(val, &(vm->arena[address]));
	return (true);
}
