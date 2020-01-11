
#include "vm_arena.h"

bool		op_zjmp(t_cursor *cursor, t_vm *vm)
{
	if (cursor && vm)
	{
		if (cursor->carry == 1)
		{
			cursor->pc = convert(&vm->arena[cursor->pos + 1], 2) % IDX_MOD;
			return (true);
		}
	}
	return (false);
}
