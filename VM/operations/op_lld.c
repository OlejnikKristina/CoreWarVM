
#include "vm_arena.h"

static int	get_reg_num(t_vm *vm, t_cursor *cursor, int type)
{
	int		reg_num;
	int		offset;

	offset = 1;
	offset += (type == IND ? 2 : 4);
	offset++;
	reg_num = vm->arena[cursor->pos + offset];
	return (reg_num - 1);
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
		value = convert(&vm->arena[index % MEM_SIZE], 4);
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
		decode_encoding_byte(vm->arena[cursor->pos + 1], args);
		reg_num = get_reg_num(vm, cursor, args[0]);
		value = get_value(vm, cursor, args[0]);
		cursor->reg[reg_num] = value;
	}
	return (true);
}
