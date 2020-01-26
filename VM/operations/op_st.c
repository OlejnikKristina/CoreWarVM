
#include "vm_arena.h"
/*Correct */
static int	get_reg_num(t_vm *vm, t_cursor *cursor)
{
	int		offset;
	int		reg_num;

	offset = 2;
	reg_num = vm->arena[(cursor->pos + offset) % MEM_SIZE];
	if (reg_num <= 0)
		return (1);
	return (reg_num);
}

static void	write_value(t_vm *vm, t_cursor *cursor, e_argctype type, long long value)
{
	int	index;
	int	offset;
	int	address;

	offset = 3;
	if (type == REG)
	{
		index = vm->arena[(cursor->pos + offset) % MEM_SIZE] - 1;
		cursor->reg[index] = value;
	}
	else if (type == IND)
	{//OPpos(133)-->xy(5;3)]op->{03 70 02 ff c4} Original draw 4 zeros on this opereation
		index = convert(&vm->arena[(cursor->pos + offset) % MEM_SIZE], 2);// from address 136 line[3] x=8 dec(880) hex(03 70)
		address = (cursor->pos + (index % IDX_MOD)) % MEM_SIZE;
		while (address < 0)					// new
			address = MEM_SIZE + address;	// new
		if (499 <= address && address <= 505) // target 501
			ft_printf("");
		write_into_memory(value, vm->arena, address);
		if (vm->flag->v)
			visual_st(vm->v->warena, vm->arena, cursor->id, address);
	}
}

bool		op_st(t_cursor *cursor, t_vm *vm)
{
	e_argctype		args[3];
	int				reg_num;
	long long int				value;

	decode_encoding_byte(vm->arena[(cursor->pos + 1) % MEM_SIZE], args);
	reg_num = get_reg_num(vm, cursor);
	value = cursor->reg[reg_num - 1];
	if (value <= 4294902016)
		ft_printf("");
	write_value(vm, cursor, args[1], value);
	return (true);
}
