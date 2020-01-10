/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_sti.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 18:04:40 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/10 15:21:40 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "vm_arena.h"

void		write_into_memory(int32_t val_to_write, uint8_t arena[])
{
	uint8_t		*pointer;

	pointer = (uint8_t *)&val_to_write;
	arena[0] = pointer[3];
	arena[1] = pointer[2];
	arena[2] = pointer[1];
	arena[3] = pointer[0];
}

int			get_arg_val(e_argctype arg_type, uint8_t arena[MEM_SIZE],
			t_cursor *cursor, int *padding)
{
	int16_t	val;
	int8_t	*pval;
	int		reg_num;

	val = 0;
	pval = (int8_t *)&val;
	if (arg_type == REG)
	{
		reg_num = arena[cursor->pos + *padding];
		if (reg_num < 1 || REG_NUMBER < reg_num)
			return (false);
		val = cursor->reg[reg_num - 1];
		*padding += REG;
	}
	else if (arg_type == DIR)
	{
		pval[0] = arena[cursor->pos + *padding];
		pval[1] += arena[cursor->pos + 1 + *padding];
		val = convert((unsigned char *)&val, 2);
		// ft_printf("\nHEX1(%.2x) DEC1(%d) HEX2(%.2x) DEC2(%d) val(%d)\n",
		// pval[0], pval[0], pval[1], pval[1], val);
		*padding += 2;
	}
	else if (arg_type == IND)
	{
		val = arena[convert(&arena[cursor->pos + *padding], 4) % IDX_MOD];
		*padding += 2;
	}
	return (val);
}

/*
	padding = 3;
	opcode(1) + encodebyte(1) + first arg REG(1)
*/

bool		op_sti(t_cursor *cursor, t_vm *vm)
{
	e_argctype	args[3];
	int32_t		val_to_write;
	int			address;
	int			padding;

	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
	val_to_write = cursor->reg[vm->arena[cursor->pos + 2] - REG];
	padding = 3;
	address = get_arg_val(args[1], vm->arena, cursor, &padding);
	address += get_arg_val(args[2], vm->arena, cursor, &padding);
	address = (address  % IDX_MOD) + cursor->pos;
	ft_printf("address(%d)\n", address);
	write_into_memory(val_to_write, &(vm->arena[address]));
	return (true);
}

/*
	padding = 2;
	opcode(1) + encodebyte(1)
*/

// bool		op_ldi(t_cursor *cursor, t_vm *vm)
// {
// 	e_argctype	args[3];
// 	int32_t		val_to_write;
// 	int			reg_num;
// 	int			address;
// 	int			padding;

// 	padding = 2;
// 	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
// 	address = get_arg_val(args[1], vm->arena, cursor, &padding);
// 	address += get_arg_val(args[2], vm->arena, cursor, &padding);
// 	address = (address  % IDX_MOD) + cursor->pos % MEM_SIZE;
// 	reg_num = vm->arena[cursor->pos + padding] - 1;
// 	cursor->reg[reg_num] = ;
// 	write_into_memory(val_to_write, &(vm->arena[address]));
// 	return (true);
// }