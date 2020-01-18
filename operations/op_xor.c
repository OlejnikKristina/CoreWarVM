
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
	reg_num = vm->arena[cursor->pos + offset] - 1;
	return (reg_num);
}

static int	set_value(t_vm *vm, t_cursor *cursor, int type, int curr)
{
	int		value;

	if (type == REG)
		return (cursor->reg[curr - 1]);
	else if (type == DIR)
		return (curr);
	value = convert(&vm->arena[(cursor->pos + (curr % IDX_MOD)) % MEM_SIZE], 4);
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
	a = convert(&vm->arena[cursor->pos + offset], size);
	offset += get_offset(args[0]);
	size = get_offset(args[1]);
	b = convert(&vm->arena[cursor->pos + offset], size);
	a = set_value(vm, cursor, args[0], a);
	b = set_value(vm, cursor, args[1], b);
	return (a ^ b);
}

bool		op_xor(t_cursor *cursor, t_vm *vm)
{
	e_argctype	args[3];
	int			reg_num;
	int			value;

	if (cursor && vm)
	{
		decode_encoding_byte(vm->arena[cursor->pos + 1], args);
		reg_num = get_reg_num(vm, cursor, args);
		value = get_value(vm, cursor, args);
		cursor->reg[reg_num] = value;
		return (true);
	}
	return (true);
}
