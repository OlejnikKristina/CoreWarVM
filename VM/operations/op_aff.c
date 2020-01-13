
#include "vm_arena.h"

bool		op_aff(t_cursor *cursor, t_vm *vm)
{
	if (cursor && vm)
	{
		ft_putchar((char)cursor->reg[vm->arena[cursor->pos + 1]]);
		return (true);
	}
	return (false);
}
