
#include "vm_arena.h"

static int	get_value(t_vm *vm, t_cursor *cursor)
{
	int		value;

	value = convert(&vm->arena[cursor->pos + 1], 2);
	return (value % IDX_MOD);
}

bool		op_lfork(t_cursor *cursor, t_vm *vm)
{
	int		value;
	int		new_pos;

	value = get_value(vm, cursor);
	new_pos = 0;
	ft_printf("value %d\n", value);
	if (cursor && vm)
		;
	return (true);
}
