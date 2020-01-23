
#include "vm_arena.h"

static int	get_offset(int type)
{
	if (type == REG)
		return (1);
	else if (type == IND)
		return (2);
	return (4);
}

static int	get_reg_num(t_vm *vm, t_cursor *cursor, e_argctype args[3])
{
	int		offset;
	int		reg_num;

	offset = 2;
	offset += get_offset(args[0]);
	offset += get_offset(args[1]);
	reg_num = vm->arena[(cursor->pos + offset) % MEM_SIZE];
	return (reg_num - 1);
}

static int	set_value(t_vm *vm, t_cursor *cursor, int type, int curr)
{
	int		value;
	int		index;

	if (type == REG)
		return (cursor->reg[curr - 1]);
	else if (type == DIR)
		return (curr);
	index = (cursor->pos + (curr % IDX_MOD));
	while (MEM_SIZE <= index)
		index -= MEM_SIZE;
	value = convert(&vm->arena[index], 4);
	return (value);
}

static int	get_value(t_vm *vm, t_cursor *cursor, e_argctype args[3])
{
	int		offset;
	int		size;
	int		a;
	int		b;

	offset = 2;
	size = get_offset(args[0]);
	a = convert(&vm->arena[(cursor->pos + offset) % MEM_SIZE], size);
	offset += get_offset(args[0]);
	size = get_offset(args[1]);
	b = convert(&vm->arena[(cursor->pos + offset) % MEM_SIZE], size);
	a = set_value(vm, cursor, args[0], a);
	b = set_value(vm, cursor, args[1], b);
	return (a | b);
}

bool		op_or(t_cursor *cursor, t_vm *vm)
{
	e_argctype	args[3];
	int			reg_num;
	int			value;

	if (cursor && vm)
	{
		decode_encoding_byte(vm->arena[(cursor->pos + 1) % MEM_SIZE], args);
		reg_num = get_reg_num(vm, cursor, args);
		value = get_value(vm, cursor, args);
		cursor->reg[reg_num] = value;
		return (true);
	}
	// if (cursor && vm)
	// {
	// 	if (args[0] == IND && args[1] == IND && args[2] == REG)
	// 	{
	// 		cursor->reg[vm->arena[cursor->pos + 6] - 1] =
	// 		convert(&vm->arena[cursor->pos + 3], 2) % IDX_MOD |
	// 		convert(&vm->arena[cursor->pos + 5], 2) % IDX_MOD;
	// 		cursor->carry = (cursor->reg[vm->arena[cursor->pos + 6] - 1] == 0 ? 1 : 0);
	// 	}
	// 	if (args[0] == DIR && args[1] == DIR && args[2] == REG)
	// 	{
	// 		cursor->reg[vm->arena[cursor->pos + 10] - 1] =
	// 		vm->arena[cursor->pos + convert(&vm->arena[cursor->pos + 2], 4)] |
	// 		vm->arena[cursor->pos + convert(&vm->arena[cursor->pos + 6], 4)];
	// 		cursor->carry = (cursor->reg[vm->arena[cursor->pos + 10] - 1] == 0 ? 1 : 0);
	// 	}
	// 	if (args[0] == REG && args[1] == REG && args[2] == REG)
	// 	{
	// 		cursor->reg[vm->arena[cursor->pos + 4] - 1] = 
	// 		cursor->reg[vm->arena[cursor->pos + 2] - 1] |
	// 		cursor->reg[vm->arena[cursor->pos + 3] - 1];
	// 		cursor->carry = (cursor->reg[vm->arena[cursor->pos + 4] - 1] == 0 ? 1 : 0);
	// 	}
	// 	if (args[0] == IND && args[1] == REG && args[2] == REG)
	// 	{
	// 		cursor->reg[vm->arena[cursor->pos + 5] - 1] =
	// 		convert(&vm->arena[cursor->pos + 3], 2) % IDX_MOD |
	// 		cursor->reg[vm->arena[cursor->pos + 4] - 1]; 
	// 		cursor->carry = (cursor->reg[vm->arena[cursor->pos + 5] - 1] == 0 ? 1 : 0);
	// 	}
	// 	if (args[0] == REG && args[1] == IND && args[2] == REG)
	// 	{
	// 		cursor->reg[vm->arena[cursor->pos + 5] - 1] = 
	// 		cursor->reg[vm->arena[cursor->pos + 2] - 1] |
	// 		convert(&vm->arena[cursor->pos + 4], 2) % IDX_MOD;
	// 		cursor->carry = (cursor->reg[vm->arena[cursor->pos + 5] - 1] == 0 ? 1 : 0);
	// 	}
	// 	if (args[0] == IND && args[1] == DIR && args[2] == REG)
	// 	{
	// 		cursor->reg[vm->arena[cursor->pos + 8] - 1] =
	// 		convert(&vm->arena[cursor->pos + 2], 2) % IDX_MOD |
	// 		vm->arena[cursor->pos + convert(&vm->arena[cursor->pos + 4], 4)];
	// 		cursor->carry = (cursor->reg[vm->arena[cursor->pos + 7] - 1] == 0 ? 1 : 0);
	// 	}
	// 	if (args[0] == DIR && args[1] == IND && args[2] == REG)
	// 	{
	// 		cursor->reg[vm->arena[cursor->pos + 8] - 1] = 
	// 		vm->arena[cursor->pos + convert(&vm->arena[cursor->pos + 2], 4)] |
	// 		convert(&vm->arena[cursor->pos + 5], 2) % IDX_MOD;
	// 		cursor->carry = (cursor->reg[vm->arena[cursor->pos + 8] - 1] == 0 ? 1 : 0);
	// 	}
	// 	if (args[0] == DIR && args[1] == REG && args[2] == REG)
	// 	{
	// 		cursor->reg[vm->arena[cursor->pos + 7] - 1] =
	// 		vm->arena[cursor->pos + convert(&vm->arena[cursor->pos + 2], 4)] |
	// 		cursor->reg[vm->arena[cursor->pos + 6] - 1];
	// 	}
	// 	if (args[0] == REG && args[1] == DIR && args[2] == REG)
	// 	{
	// 		cursor->reg[vm->arena[cursor->pos + 7] - 1] =
	// 		cursor->reg[vm->arena[cursor->pos + 2] - 1] |
	// 		vm->arena[cursor->pos + convert(&vm->arena[cursor->pos + 3], 4)];
	// 	}
	// 	return (true);
	// }
	return (false);
}
