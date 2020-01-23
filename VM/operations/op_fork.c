
#include "vm_arena.h"

static int	get_value(t_vm *vm, t_cursor *cursor)
{
	int		value;

	value = convert(&vm->arena[(cursor->pos + 1) % MEM_SIZE], 2);
	value = (value < 0 ? value : value % IDX_MOD);
	while (MEM_SIZE <= value)
		value -= MEM_SIZE;
	return (value);
}

static void	copy_regs(t_cursor *new, int32_t reg[16])
{
	int		i;

	i = 0;
	while (i < REG_NUMBER)
	{
		new->reg[i] = reg[i];
		i++;
	}
}

void	insert_to_beg(t_vm *vm, t_cursor *new)
{
	new->next = vm->cursor;
	vm->cursor = new;
}

bool		op_fork(t_cursor *cursor, t_vm *vm)
{
	int			new_pc;
	t_cursor	*new;

	new_pc = get_value(vm, cursor);
	new = init_cursor(cursor->id, cursor->pos, cursor->opcode, vm->arena[(cursor->pos + 1) % MEM_SIZE]);
	copy_regs(new, cursor->reg);
	new->last_live = cursor->last_live;
	new->carry = cursor->carry;
	insert_to_beg(vm, new);
	new->pos += new_pc;
	while (MEM_SIZE <= new->pos)
		new->pos -= MEM_SIZE;
	new->opcode = vm->arena[new->pos];
	new->pc =
	calculate_program_counter(new->opcode, vm->arena[(new->pos + 1) % MEM_SIZE]);
	new->wait_cycles = get_waite_cycle(new->opcode);
	vm->process++;
	return (true);
}
