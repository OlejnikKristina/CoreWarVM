
#include "vm_arena.h"

static int	get_reg_num(t_vm *vm, t_cursor *cursor)
{
	int		offset;
	int		reg_num;

	offset = 2;
	reg_num = vm->arena[cursor->pos + offset] - 1;
	return (reg_num);
}

static void	write_value(t_vm *vm, t_cursor *cursor, int type, int value)
{
	int	index;
	int	offset;
	int	address;

	offset = 3;
	if (type == REG)
	{
		index = vm->arena[cursor->pos + offset] - 1;
		cursor->reg[index] = value;
	}
	else if (type == IND)
	{
		index = convert(&vm->arena[cursor->pos + offset], 2);
		address = (index % IDX_MOD) + cursor->pos;
		write_into_memory(value, vm->arena, address);
		if (vm->flag->v)
			visual_sti(vm->v->warena, &(vm->arena[address]), cursor->id, address);
	}
}

bool		op_st(t_cursor *cursor, t_vm *vm)
{
	e_argctype	args[3];
	int			reg_num;
	int			value;

	if (cursor && vm)
	{
		decode_encoding_byte(vm->arena[cursor->pos + 1], args);
		reg_num = get_reg_num(vm, cursor);
		value = cursor->reg[reg_num];
		write_value(vm, cursor, args[1], value);
		return (true);
	}
	return (false);
}
