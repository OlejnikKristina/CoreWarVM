/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_ld.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 13:22:15 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/23 13:59:30 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

	// if (!(value == 0 || value == 57672192 || value == 318992387 || value == 436432899 || value == 4294902016 || value == 386101251 ||
	// value == 251883523 || value == 251883523))
	// {
	// 	int imhere = 1;
	// 	imhere++;
	// }

int			get_reg_num(t_vm *vm, int position, e_argctype type)
{
	int		reg_num;
	int		offset;

	offset = 2;
	offset += (type == IND ? 2 : 4);
	reg_num = vm->arena[((position + offset) % MEM_SIZE)];
	return (reg_num);	
}

long long int		get_value(t_vm *vm, int position, e_argctype type)
{
	long long int	value;
	int		offset;
	int		size;

	offset = 2;
	size = (type == IND ? 2 : 4);
	value = convert(&vm->arena[((position + offset) % MEM_SIZE)], size);
	if (type == IND)
	{
		value = position + (value % IDX_MOD);
		value = convert(&vm->arena[(value + offset) % MEM_SIZE], 4);
	}
	return (value);
}

bool		op_ld(t_cursor *cursor, t_vm *vm)
{
	e_argctype		args[3];
	int				reg_num;
	long long int	value;

	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
	reg_num = get_reg_num(vm, cursor->pos, args[0]);
	value = get_value(vm, cursor->pos, args[0]);
	cursor->reg[reg_num - 1] = value;
	cursor->carry = (cursor->reg[reg_num - 1] == 0 ? 1 : 0);
	return (true);
}
