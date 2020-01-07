
#include "vm_arena.h"

bool		op_zjmp(t_cursor *cursor, t_vm *vm)
{
	if (cursor && vm)
	{
		if (cursor->carry == 1)
		{
			cursor->pos +=
			convert(&vm->arena[cursor->pos + 1], 4) % IDX_MOD;
		}
	}
	return (true);
}
