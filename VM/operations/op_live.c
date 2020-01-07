
#include "vm_arena.h"

bool		op_live(t_cursor *cursor, t_vm *vm)
{
	int		val;

	val = convert(&vm->arena[cursor->pos + 1], 4);
	if (cursor && vm)
	{
		if (val == cursor->reg[0])
		{
			cursor->last_live = vm->current_cycle;
			vm->nbr_lives++;
			vm->last_alive = cursor->reg[0];
			return (true);
		}
	}
	return (false);
}
