
#include "vm_arena.h"

bool		op_st(t_cursor *cursor, t_vm *vm)
{
	e_argctype	args[3];

	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
	if (cursor && vm)
	{
		if (args[0] == REG && args[1] == REG)
		{
			cursor->reg[vm->arena[cursor->pos + 3]] = 
			cursor->reg[vm->arena[cursor->pos + 2]];
		}
		else if (args[0] == REG && args[1] == IND)
		{
			cursor->reg[vm->arena[cursor->pos + 3]] = 
			convert(&vm->arena[cursor->pos + 1], 2) % IDX_MOD;
		}
		return (true);
	}
	return (false);
}
