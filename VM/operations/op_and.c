
#include "vm_arena.h"

bool		op_and(t_cursor *cursor, t_vm *vm)
{
	e_argctype	args[3];

	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
	if (cursor && vm)
	{
		if (args[0] == IND && args[1] == IND && args[2] == REG)
		{
			cursor->reg[vm->arena[cursor->pos + 6] - 1] = vm->arena[cursor->pos + 3] & vm->arena[cursor->pos + 5];
			cursor->carry = (cursor->reg[vm->arena[cursor->pos + 6] - 1] == 0 ? 1 : 0);
		}
		if (args[0] == DIR && args[1] == DIR && args[2] == REG)
		{
			cursor->reg[vm->arena[cursor->pos + 10] - 1] =
			vm->arena[cursor->pos + convert(&vm->arena[cursor->pos + 2], 4)] &
			vm->arena[cursor->pos + convert(&vm->arena[cursor->pos + 6], 4)];
			cursor->carry = (cursor->reg[vm->arena[cursor->pos + 10] - 1] == 0 ? 1 : 0);
		}
			;
		if (args[0] == REG && args[1] == REG && args[2] == REG)
			;
		if (args[0] == IND && args[1] == REG && args[2] == REG)
			;
		if (args[0] == REG && args[1] == IND && args[2] == REG)
			;
		if (args[0] == IND && args[1] == DIR && args[2] == REG)
			;
		if (args[0] == DIR && args[1] == IND && args[2] == REG)
			;
		if (args[0] == DIR && args[1] == REG && args[2] == REG)
			;
		if (args[0] == REG && args[1] == DIR && args[2] == REG)
			;





		return (true);
	}
	return (false);
}
