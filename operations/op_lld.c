/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_lld.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 21:30:57 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/30 21:30:59 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

static int	get_reg_num(t_vm *vm, t_cursor *cursor, int type)
{
	int		reg_num;
	int		offset;

	offset = 1;
	offset += (type == IND ? 2 : 4);
	offset++;
	reg_num = vm->arena[(cursor->pos + offset) % MEM_SIZE];
	return (reg_num);
}

static int	get_value(t_vm *vm, t_cursor *cursor, int type)
{
	int		size;
	int		offset;
	int		value;
	int		index;

	offset = 2;
	size = (type == IND ? 2 : 4);
	if (type == IND)
	{
		index = cursor->pos +
		convert(&vm->arena[cursor->pos + offset], size);
		while (MEM_SIZE <= index)
			index -= MEM_SIZE;
		value = convert(&vm->arena[index], 4);
	}
	else
	{
		value = convert(&vm->arena[(cursor->pos + offset) %
		MEM_SIZE], size);
	}
	return (value);
}

bool		op_lld(t_cursor *cursor, t_vm *vm)
{
	e_argctype	args[3];
	int			reg_num;
	int			value;

	if (cursor && vm)
	{
		decode_encoding_byte(vm->arena[(cursor->pos + 1) % MEM_SIZE], args);
		reg_num = get_reg_num(vm, cursor, args[0]);
		value = get_value(vm, cursor, args[0]);
		cursor->reg[reg_num - 1] = value;
		cursor->carry = (cursor->reg[reg_num - 1] == 0 ? 1 : 0);
	}
	return (true);
}
