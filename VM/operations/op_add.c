
#include "vm_arena.h"

bool		op_add(t_cursor *cursor, t_vm *vm)
{
	if (cursor && vm)
	{
		ft_printf("added %d to %d = %d\n", cursor->reg[vm->arena[cursor->pos + 2] - 1],
		cursor->reg[vm->arena[cursor->pos + 3] - 1], cursor->reg[vm->arena[cursor->pos + 4] - 1]);
		cursor->reg[vm->arena[cursor->pos + 4] - 1] = 
		cursor->reg[vm->arena[cursor->pos + 3] - 1] + cursor->reg[vm->arena[cursor->pos + 2] - 1];
		return (true);
	}
	return (false);
}
