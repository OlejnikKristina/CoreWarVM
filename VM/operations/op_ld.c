
#include "vm_arena.h"

bool		op_ld(t_cursor *cursor, t_vm *vm)
{
	e_argctype	args[3];
	int			reg_num;
	int			reg_val;

	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
	if (cursor && vm)
	{
		if (args[0] == IND && args[1] == REG)
		{
			reg_num = vm->arena[cursor->pos + 4] - 1;
			cursor->reg[reg_num] = (vm->arena[cursor->pos + 3] % IDX_MOD);
			ft_printf("loaded %d into r%d = %d\n",
			vm->arena[cursor->pos + 3], vm->arena[cursor->pos + 4],
			cursor->reg[reg_num]);
		}
		else if (args[0] == DIR && args[1] == REG)
		{
			reg_num = vm->arena[cursor->pos + 6] - 1;
			reg_val = vm->arena[cursor->pos + 2];
			// ft_printf("\nREG NUM [%d] DIR VAL dec(%d) hex[%x] ", reg_num, reg_val, reg_val);
			// ft_printf("Dir val converted: %d\n", convert(&vm->arena[cursor->pos + 2], 4));
			cursor->reg[reg_num] = reg_val;
			cursor->carry = (reg_val == 0) ? true : false;
			// ft_printf("loaded %d into r%d = %d\n", vm->arena[cursor->pos + convert(&vm->arena[cursor->pos + 2], 4)],
			// vm->arena[reg_num], cursor->reg[vm->arena[reg_num] - 1]);
		}
		else
			return (false);
		return (true);
	}
	return (false);
}
