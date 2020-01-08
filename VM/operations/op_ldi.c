
#include "vm_arena.h"

bool		op_ldi(t_cursor *cursor, t_vm *vm)
{
	e_argctype args[3];

	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
	if (cursor && vm)
	{
		if (args[0] == REG && args[1] == REG && args[2] == REG)
		{
			cursor->reg[vm->arena[cursor->pos + 4]] =
			convert(&vm->arena[((cursor->pos + (cursor->reg[vm->arena[cursor->pos + 2]] +
			cursor->reg[vm->arena[cursor->pos + 3]])) % IDX_MOD) % MEM_SIZE], 4);
			ft_printf("LDI %d into r%d : %d\n", convert(&vm->arena[((cursor->pos +
			(cursor->reg[vm->arena[cursor->pos + 2]] +
			cursor->reg[vm->arena[cursor->pos + 3]])) % IDX_MOD) % MEM_SIZE], 4),
			vm->arena[cursor->pos + 4],
			cursor->reg[vm->arena[cursor->pos + 4]]);
		}
		if (args[0] == REG && args[1] == DIR && args[2] == REG)
		{
			cursor->reg[vm->arena[cursor->pos + 5]] =
			convert(&vm->arena[cursor->pos + (cursor->reg[vm->arena[cursor->pos + 2]] +
			convert(&vm->arena[cursor->pos + 3], 2))], 4);
			ft_printf("LDI %d into r%d : %d\n", convert(&vm->arena[cursor->pos +
			(cursor->reg[vm->arena[cursor->pos + 2]] +
			convert(&vm->arena[cursor->pos + 3], 2))], 4), vm->arena[cursor->pos + 5],
			cursor->reg[vm->arena[cursor->pos + 5]]);
		}
		if (args[0] == DIR && args[1] == DIR && args[2] == REG)
		{
			cursor->reg[vm->arena[cursor->pos + 6]] = convert(
			&vm->arena[((cursor->pos + (convert(&vm->arena[cursor->pos + 2], 2) +
			convert(&vm->arena[cursor->pos + 4], 2))) % IDX_MOD) % MEM_SIZE], 4);
			ft_printf("LD %d into r%d : %d\n", convert(
			&vm->arena[((cursor->pos + (convert(&vm->arena[cursor->pos + 2], 2) +
			convert(&vm->arena[cursor->pos + 4], 2))) % IDX_MOD) % MEM_SIZE], 4),
			vm->arena[cursor->pos + 6], cursor->reg[vm->arena[cursor->pos + 6]]);
		}
		if (args[0] == DIR && args[1] == REG && args[2] == REG)
		{
			cursor->reg[vm->arena[cursor->pos + 5]] = convert(
			&vm->arena[((cursor->pos + (convert(&vm->arena[cursor->pos + 2], 2) +
			cursor->reg[vm->arena[cursor->pos + 4]])) % IDX_MOD) % MEM_SIZE], 4);
			ft_printf("LDI %d into r%d : %d\n", convert(
			&vm->arena[((cursor->pos + (convert(&vm->arena[cursor->pos + 2], 2) +
			cursor->reg[vm->arena[cursor->pos + 4]])) % IDX_MOD) % MEM_SIZE], 4),
			vm->arena[cursor->pos + 5], cursor->reg[vm->arena[cursor->pos + 5]]);
		}
		if (args[0] == IND && args[1] == REG && args[2] == REG)
		{
			cursor->reg[vm->arena[cursor->pos + 5]] = convert(
			&vm->arena[(cursor->pos +
			(convert(&vm->arena[cursor->pos + convert(&vm->arena[cursor->pos + 2], 2)], 4) +
			cursor->reg[vm->arena[cursor->pos + 4]]) % IDX_MOD) % MEM_SIZE], 4);
			ft_printf("LDI %d into r%d : %d\n", convert(
			&vm->arena[(cursor->pos +
			(convert(&vm->arena[cursor->pos + convert(&vm->arena[cursor->pos + 2], 2)], 4) +
			cursor->reg[vm->arena[cursor->pos + 4]]) % IDX_MOD) % MEM_SIZE], 4), vm->arena[cursor->pos + 5],
			cursor->reg[vm->arena[cursor->pos + 5]]);
		}
		if (args[0] == IND && args[1] == DIR && args[2] == REG)
		{
			cursor->reg[vm->arena[cursor->pos + 6]] = convert(
			&vm->arena[((cursor->pos + 
			(convert(&vm->arena[cursor->pos + convert(&vm->arena[cursor->pos + 2], 2)], 4) +
			convert(&vm->arena[cursor->pos + 4], 2))) % IDX_MOD) % MEM_SIZE], 4);
			ft_printf("LDI %d into r%d : %d\n", convert(
			&vm->arena[((cursor->pos + 
			(convert(&vm->arena[cursor->pos + convert(&vm->arena[cursor->pos + 2], 2)], 4) +
			convert(&vm->arena[cursor->pos + 4], 2))) % IDX_MOD) % MEM_SIZE], 4),
			vm->arena[cursor->pos + 6], cursor->reg[vm->arena[cursor->pos + 6]]);
		}
		return (true);
	}
	return (false);
}
