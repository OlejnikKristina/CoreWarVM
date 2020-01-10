
#include "vm_arena.h"

static int	get_offset(int type)
{
	if (type == REG)
		return (1);
	return (2);
}

static int	get_reg_num(t_vm *vm, t_cursor *cursor, e_argctype args[3])
{
	int		offset;
	int		reg_num;

	offset = 2;
	offset += get_offset(args[0]);
	offset += get_offset(args[1]);
	reg_num = vm->arena[cursor->pos + offset] - 1;
	return (reg_num);
}

// static int	get_value(t_vm *vm, t_cursor *cursor, e_argctype args[3])
// {
// 	int		offset;
// 	int		size;
// 	int		a;
// 	int		b;

// 	offset = 2;
// 	size = get_offset(args[0]);
// 	a = convert(&vm->arena[cursor->pos + offset], size);
// 	offset += get_offset(args[0]);
// 	size = get_offset(args[1]);
// 	b = convert(&vm->arena[cursor->pos + offset], size);
// 	a = set_value(vm, cursor, args[0], a);
// 	b = set_value(vm, cursor, args[1], b);
// 	return ((a + b) % IDX_MOD);
// }

bool		op_ldi(t_cursor *cursor, t_vm *vm)
{
	e_argctype	args[3];
	int			reg_num;
	// int			value;

	decode_encoding_byte(vm->arena[cursor->pos + 1], args);
	reg_num = get_reg_num(vm, cursor, args);
	// value = get_value(vm, cursor, args);
	ft_printf("r%d\n", reg_num + 1);
	// if (cursor && vm)
	// {
	// 	if (args[0] == REG && args[1] == REG && args[2] == REG)
	// 	{
	// 		cursor->reg[vm->arena[cursor->pos + 4]] =
	// 		convert(&vm->arena[((cursor->pos + (cursor->reg[vm->arena[cursor->pos + 2]] +
	// 		cursor->reg[vm->arena[cursor->pos + 3]])) % IDX_MOD) % MEM_SIZE], 4);
	// 		ft_printf("LDI %d into r%d : %d\n", convert(&vm->arena[((cursor->pos +
	// 		(cursor->reg[vm->arena[cursor->pos + 2]] +
	// 		cursor->reg[vm->arena[cursor->pos + 3]])) % IDX_MOD) % MEM_SIZE], 4),
	// 		vm->arena[cursor->pos + 4],
	// 		cursor->reg[vm->arena[cursor->pos + 4]]);
	// 	}
	// 	if (args[0] == REG && args[1] == DIR && args[2] == REG)
	// 	{
	// 		cursor->reg[vm->arena[cursor->pos + 5]] =
	// 		convert(&vm->arena[cursor->pos + (cursor->reg[vm->arena[cursor->pos + 2]] +
	// 		convert(&vm->arena[cursor->pos + 3], 2))], 4);
	// 		ft_printf("LDI %d into r%d : %d\n", convert(&vm->arena[cursor->pos +
	// 		(cursor->reg[vm->arena[cursor->pos + 2]] +
	// 		convert(&vm->arena[cursor->pos + 3], 2))], 4), vm->arena[cursor->pos + 5],
	// 		cursor->reg[vm->arena[cursor->pos + 5]]);
	// 	}
	// 	if (args[0] == DIR && args[1] == DIR && args[2] == REG)
	// 	{
	// 		cursor->reg[vm->arena[cursor->pos + 6]] = convert(
	// 		&vm->arena[((cursor->pos + (convert(&vm->arena[cursor->pos + 2], 2) +
	// 		convert(&vm->arena[cursor->pos + 4], 2))) % IDX_MOD) % MEM_SIZE], 4);
	// 		ft_printf("LD %d into r%d : %d\n", convert(
	// 		&vm->arena[((cursor->pos + (convert(&vm->arena[cursor->pos + 2], 2) +
	// 		convert(&vm->arena[cursor->pos + 4], 2))) % IDX_MOD) % MEM_SIZE], 4),
	// 		vm->arena[cursor->pos + 6], cursor->reg[vm->arena[cursor->pos + 6]]);
	// 	}
	// 	if (args[0] == DIR && args[1] == REG && args[2] == REG)
	// 	{
	// 		cursor->reg[vm->arena[cursor->pos + 5]] = convert(
	// 		&vm->arena[((cursor->pos + (convert(&vm->arena[cursor->pos + 2], 2) +
	// 		cursor->reg[vm->arena[cursor->pos + 4]])) % IDX_MOD) % MEM_SIZE], 4);
	// 		ft_printf("LDI %d into r%d : %d\n", convert(
	// 		&vm->arena[((cursor->pos + (convert(&vm->arena[cursor->pos + 2], 2) +
	// 		cursor->reg[vm->arena[cursor->pos + 4]])) % IDX_MOD) % MEM_SIZE], 4),
	// 		vm->arena[cursor->pos + 5], cursor->reg[vm->arena[cursor->pos + 5]]);
	// 	}
	// 	if (args[0] == IND && args[1] == REG && args[2] == REG)
	// 	{
	// 		cursor->reg[vm->arena[cursor->pos + 5]] = convert(
	// 		&vm->arena[(cursor->pos +
	// 		(convert(&vm->arena[cursor->pos + convert(&vm->arena[cursor->pos + 2], 2)], 4) +
	// 		cursor->reg[vm->arena[cursor->pos + 4]]) % IDX_MOD) % MEM_SIZE], 4);
	// 		ft_printf("LDI %d into r%d : %d\n", convert(
	// 		&vm->arena[(cursor->pos +
	// 		(convert(&vm->arena[cursor->pos + convert(&vm->arena[cursor->pos + 2], 2)], 4) +
	// 		cursor->reg[vm->arena[cursor->pos + 4]]) % IDX_MOD) % MEM_SIZE], 4), vm->arena[cursor->pos + 5],
	// 		cursor->reg[vm->arena[cursor->pos + 5]]);
	// 	}
	// 	if (args[0] == IND && args[1] == DIR && args[2] == REG)
	// 	{
	// 		cursor->reg[vm->arena[cursor->pos + 6]] = convert(
	// 		&vm->arena[((cursor->pos + 
	// 		(convert(&vm->arena[cursor->pos + convert(&vm->arena[cursor->pos + 2], 2)], 4) +
	// 		convert(&vm->arena[cursor->pos + 4], 2))) % IDX_MOD) % MEM_SIZE], 4);
	// 		ft_printf("LDI %d into r%d : %d\n", convert(
	// 		&vm->arena[((cursor->pos + 
	// 		(convert(&vm->arena[cursor->pos + convert(&vm->arena[cursor->pos + 2], 2)], 4) +
	// 		convert(&vm->arena[cursor->pos + 4], 2))) % IDX_MOD) % MEM_SIZE], 4),
	// 		vm->arena[cursor->pos + 6], cursor->reg[vm->arena[cursor->pos + 6]]);
	// 	}
	// 	return (true);
	// }
	return (false);
}
