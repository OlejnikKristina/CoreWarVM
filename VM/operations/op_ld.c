
#include "vm_arena.h"

bool		op_ld(t_cursor *cursor, t_vm *vm)
{
	e_argctype args[3];

	ft_printf("gets here\n");
	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
	for (int i = 0; i < 3; i++) {
		if (args[i] == REG)
			ft_printf("REG\n");
		if (args[i] == DIR)
			ft_printf("DIR\n");
		if (args[i] == IND)
			ft_printf("IND\n");
	}
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
			ft_printf("DIR bytes %d\n", vm->arena[cursor->pos + 2]);
		}
		else
			return (false);
		return (true);
	}
	return (false);
}
