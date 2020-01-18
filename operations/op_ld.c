/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_ld.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 13:22:15 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/17 17:58:54 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

int			get_reg_num(t_vm *vm, t_cursor *cursor, int type)
{
	int		reg_num;
	int		offset;

	offset = 1;
	offset += (type == IND ? 3 : 5);
	reg_num = vm->arena[cursor->pos + offset];
	return (reg_num);	
}

int32_t		get_value(t_vm *vm, t_cursor *cursor, int type)
{
	int32_t	value;
	int		offset;
	int		size;

	offset = 2;
	size = (type == IND ? 2 : 4);
	value = (int32_t)convert(&vm->arena[cursor->pos + offset], size);
	return (value);
}

bool		op_ld(t_cursor *cursor, t_vm *vm)
{
	e_argctype	args[3];
	int			reg_num;
	int32_t		value;

	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
	if (cursor && vm)
	{
		reg_num = get_reg_num(vm, cursor, args[0]) - 1;
		value = get_value(vm, cursor, args[0]);
		cursor->reg[reg_num] = value;
		cursor->carry = (cursor->reg[reg_num] == 0 ? 1 : 0);
		return (true);
	}
	return (false);
}
