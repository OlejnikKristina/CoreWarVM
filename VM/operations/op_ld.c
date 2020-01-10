/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_ld.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 13:22:15 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/10 16:38:34 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"


bool		op_ld(t_cursor *cursor, t_vm *vm)
{
	e_argctype	args[3];
	int			reg_num;

	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
	if (cursor && vm)
	{
		if (args[0] == IND && args[1] == REG)
		{
			reg_num = vm->arena[cursor->pos + 4];
			cursor->reg[reg_num] = 
			convert(&vm->arena[((cursor->pos + convert(&vm->arena[cursor->pos + 2], 2) % IDX_MOD) % MEM_SIZE)], 4);

			ft_printf("LD %d into r%d = %d\n",
			convert(&vm->arena[((cursor->pos + convert(&vm->arena[cursor->pos + 2], 2) % IDX_MOD) % MEM_SIZE)], 4),
			vm->arena[cursor->pos + 4],
			cursor->reg[reg_num]);

			cursor->carry = (cursor->reg[reg_num] = 0 ? 1 : 0);
		}
		else if (args[0] == DIR && args[1] == REG)
		{
			reg_num = vm->arena[cursor->pos + 6] - 1;
			cursor->reg[reg_num] = convert(&vm->arena[cursor->pos + 2], 4);
			ft_printf("LD %d into r%d = %d\n", convert(&vm->arena[cursor->pos + 2], 4),
			vm->arena[cursor->pos + 6], cursor->reg[reg_num]);
			cursor->carry = (cursor->reg[reg_num] == 0 ? 1 : 0);
		}
		else
			return (false);
		return (true);
	}
	return (false);
}

