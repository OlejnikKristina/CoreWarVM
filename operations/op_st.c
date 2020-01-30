/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_st.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 16:39:34 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/30 21:32:42 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

static int	get_reg_num(t_vm *vm, t_cursor *cursor)
{
	int		offset;
	int		reg_num;

	offset = 2;
	reg_num = vm->arena[(cursor->pos + offset) % MEM_SIZE];
	if (reg_num <= 0)
		return (1);
	return (reg_num);
}

static void	write_value(t_vm *vm, t_cursor *cursor, e_argctype type, long long value)
{
	int	index;
	int	offset;
	int	address;

	offset = 3;
	if (type == REG)
	{
		index = vm->arena[(cursor->pos + offset) % MEM_SIZE] - 1;
		cursor->reg[index] = value;
	}
	else if (type == IND)
	{
		index = convert(&vm->arena[(cursor->pos + offset) % MEM_SIZE], 2);
		address = (cursor->pos + (index % IDX_MOD)) % MEM_SIZE;
		while (address < 0)
			address = MEM_SIZE + address;
		write_into_memory(value, vm->arena, address);
		if (vm->flag->v)
			visual_store(vm->v->warena, vm->arena, cursor->id, address);
	}
}

bool		op_st(t_cursor *cursor, t_vm *vm)
{
	e_argctype		args[3];
	int				reg_num;
	long long int				value;

	decode_encoding_byte(vm->arena[(cursor->pos + 1) % MEM_SIZE], args);
	reg_num = get_reg_num(vm, cursor);
	value = cursor->reg[reg_num - 1];
	write_value(vm, cursor, args[1], value);
	return (true);
}
