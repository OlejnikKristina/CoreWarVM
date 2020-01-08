
#include "vm_arena.h"

bool		op_st(t_cursor *cursor, t_vm *vm)
{
	e_argctype	args[3];

	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
	if (cursor && vm)
	{
		if (args[0] == REG && args[1] == REG)
		{
			cursor->reg[vm->arena[cursor->pos + 3] - 1] = 
			cursor->reg[vm->arena[cursor->pos + 2] - 1];
			ft_printf("ST r%d:%d into r%d:%d\n", vm->arena[cursor->pos + 2],
			cursor->reg[vm->arena[cursor->pos + 2] - 1], vm->arena[cursor->pos + 3],
			cursor->reg[vm->arena[cursor->pos + 3] - 1]);
		}
		else if (args[0] == REG && args[1] == IND)
		{
			cursor->reg[vm->arena[cursor->pos + 2] - 1] = 
			vm->arena[(cursor->pos + convert(&vm->arena[cursor->pos + 3], 2) % IDX_MOD) % MEM_SIZE];
			ft_printf("ST %d into r%d:%d\n", vm->arena[(cursor->pos +
			convert(&vm->arena[cursor->pos + 3], 2) % IDX_MOD) % MEM_SIZE],
			vm->arena[cursor->pos + 2], cursor->reg[vm->arena[cursor->pos + 2] - 1]);
		}
		return (true);
	}
	return (false);
}
