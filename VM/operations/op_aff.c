
#include "vm_arena.h"

bool		op_aff(t_cursor *cursor, t_vm *vm)
{
	ft_putchar((char)cursor->reg[vm->arena[((cursor->pos + 1) % MEM_SIZE)]]);
	return (true);
}
