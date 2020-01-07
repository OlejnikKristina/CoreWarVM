
#include "vm_arena.h"

bool		op_ld(t_cursor *cursor, t_vm *vm)
{
	e_argctype args[3];

	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
	if (cursor && vm)
	{
		if (args[0] == IND && args[1] == REG)
		{
			cursor->reg[vm->arena[cursor->pos + 4] - 1] = vm->arena[cursor->pos + 3];
			ft_printf("loaded %d into r%d = %d\n", vm->arena[cursor->pos + 3], vm->arena[cursor->pos + 4],
			cursor->reg[vm->arena[cursor->pos + 4] - 1]);
		}
		else if (args[0] == DIR && args[1] == REG)
		{
			cursor->reg[vm->arena[cursor->pos + 6] - 1] =
			vm->arena[cursor->pos + convert(&vm->arena[cursor->pos + 2], 4)];
			ft_printf("loaded %d into r%d = %d\n", vm->arena[cursor->pos + convert(&vm->arena[cursor->pos + 2], 4)],
			vm->arena[cursor->pos + 6], cursor->reg[vm->arena[cursor->pos + 6] - 1]);
		}
		else
			return (false);
		return (true);
	}
	return (false);
}
