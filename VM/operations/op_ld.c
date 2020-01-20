/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_ld.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 13:22:15 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/19 19:15:40 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

int			get_reg_num(t_vm *vm, t_cursor *cursor, e_argctype type)
{
	int		reg_num;
	int		offset;

	offset = 2;
	offset += (type == IND ? 2 : 4);
	reg_num = vm->arena[cursor->pos + offset];
	return (reg_num);	
}

// int32_t		get_value(t_vm *vm, t_cursor *cursor, e_argctype type)
// {
// 	int32_t	value;
// 	int		offset;
// 	int		size;

// 	offset = 2;
// 	size = (type == IND ? 2 : 4);
// 	value = (int32_t)convert(&vm->arena[cursor->pos + offset], size);
// 	return (value);
// }

int32_t		get_value(t_vm *vm, t_cursor *cursor, e_argctype type)
{
	int32_t	value;
	int		offset;
	int		size;

	offset = 2;
	size = (type == IND ? 2 : 4);
	value = (int32_t)convert(&vm->arena[cursor->pos + offset], size);
	if (type == IND)
	{
		value = cursor->pos + (value % IDX_MOD);
		value = (int32_t)convert(&vm->arena[value + offset], 4);
	}
	return (value);
}

bool		op_ld(t_cursor *cursor, t_vm *vm)
{
	e_argctype	args[3];
	int			reg_num;
	int32_t		value;

	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
	reg_num = get_reg_num(vm, cursor, args[0]);
	value = get_value(vm, cursor, args[0]);
	cursor->reg[reg_num - 1] = value;
	cursor->carry = (cursor->reg[reg_num] == 0 ? 1 : 0);
	return (true);
}
