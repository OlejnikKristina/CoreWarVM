
#include "vm_arena.h"

bool		op_sti(t_cursor *cursor, t_vm *vm)
{
	e_argctype	args[3];
	int			val;
	int			address;
	int			reg_num;
	int			third_args;

	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
	val = cursor->reg[cursor->pos + 2];
	address = 0;
	if (args[1] == REG)
	{
		reg_num = vm->arena[cursor->pos + 3];
		address = cursor->reg[reg_num];
		third_args = 1;
	}
	else if (args[1] == DIR)
	{
		address = vm->arena[cursor->pos + 3];
		third_args = 2;
	}
	else if (args[1] == IND)
	{
		address = vm->arena[convert(&vm->arena[cursor->pos + 2], 4) % IDX_MOD];
		third_args = 2;
	}
	if (args[2] == REG)
	{
		reg_num = vm->arena[cursor->pos + 3];
		address += cursor->reg[reg_num];
	}
	else if (args[2] == DIR)
	{
		address += vm->arena[cursor->pos + 4];
	}
	vm->arena[address] = val;
	ft_printf("Reg number: [%d] VAL dec(%d) hex(%d), into memory box number [%d]\n",
	cursor->pos + 2, val, val, address);
	return (true);
}
