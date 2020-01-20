
#include "vm_arena.h"

static int	get_reg_num(t_vm *vm, t_cursor *cursor)
{
	int		offset;
	int		reg_num;

	offset = 2;
	reg_num = vm->arena[cursor->pos + offset];
	if (reg_num <= 0)
		return (1);
	return (reg_num);
}

static void	write_value(t_vm *vm, t_cursor *cursor, e_argctype type, int32_t value)
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

		address = cursor->pos + (index % IDX_MOD);
		while (address < 0)						// new
			address = MEM_SIZE + address;		// new
		address = address % MEM_SIZE;
		write_into_memory(value, vm->arena, address);
		if (vm->flag->v)
			visual_st(vm->v->warena, &(vm->arena[address]), cursor->id, address);
	}
}

bool		op_st(t_cursor *cursor, t_vm *vm)
{
	e_argctype	args[3];
	int			reg_num;
	int32_t		value;

	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
	reg_num = get_reg_num(vm, cursor);
	value = cursor->reg[reg_num - 1];
	if (0 < value)
		ft_printf("");
	write_value(vm, cursor, args[1], value);
	return (true);
}
