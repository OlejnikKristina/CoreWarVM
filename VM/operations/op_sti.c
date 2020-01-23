/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_sti.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 18:04:40 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/23 14:22:36 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

void	write_into_memory(int val_to_write, uint8_t *arena, int address)
{
	uint8_t		*pointer;
	int			position;
	int			i;

	i = 0;
	pointer = (uint8_t *)&val_to_write;
	while (i < 4)
	{
		position = address + i;
		while (MEM_SIZE <= position)
			position -= MEM_SIZE;
		arena[position] = pointer[3 - i];
		i++;
	}
}

int		get_arg_val(e_argctype arg_type, uint8_t arena[MEM_SIZE],
		t_cursor *cursor, int *padding)
{
	int32_t	val;
	int8_t	*pval;
	int		reg_num;

	val = 0;
	pval = (int8_t *)&val;
	if (arg_type == REG)
	{
		reg_num = arena[(cursor->pos + *padding) % MEM_SIZE];
		if (reg_num < 1 || REG_NUMBER < reg_num)
			return (false);
		val = cursor->reg[reg_num - 1];
		*padding += REG;
	}
	else if (arg_type == DIR)
	{
		pval[0] = arena[(cursor->pos + *padding) % MEM_SIZE];
		pval[1] += arena[(cursor->pos + 1 + *padding) % MEM_SIZE];
		val = convert((unsigned char *)&val, 2);
		*padding += 2;
	}
	else if (arg_type == IND)
	{
		val = convert(&arena[(cursor->pos + *padding) % MEM_SIZE], 2);
		val = cursor->pos + (val % IDX_MOD);
		val = convert(&arena[val % MEM_SIZE], 4);
		*padding += 2;
	}
	return (val);
}

/*
	padding = 3;
	opcode(1) + encodebyte(1) + first arg REG(1)
*/

bool	op_sti(t_cursor *cursor, t_vm *vm)
{
	e_argctype	args[3];
	int32_t		val_to_write;
	int			address;
	int			padding;

	decode_encoding_byte(vm->arena[(cursor->pos + 1) % MEM_SIZE], args);
	val_to_write = cursor->reg[vm->arena[(cursor->pos + 2) % MEM_SIZE] - REG];
	padding = 3;
	address = get_arg_val(args[1], vm->arena, cursor, &padding);
	address += get_arg_val(args[2], vm->arena, cursor, &padding);
	address = (address % IDX_MOD) + cursor->pos;
	while (address < 0)					// new
		address = MEM_SIZE + address;	// new
	write_into_memory(val_to_write, vm->arena, address);
	if (vm->flag->v)
		visual_sti(vm->v->warena, vm->arena, cursor->id, address);
	return (true);
}
