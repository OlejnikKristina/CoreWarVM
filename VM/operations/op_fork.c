
#include "vm_arena.h"

static int	get_value(t_vm *vm, t_cursor *cursor)
{
	int		value;

	value = convert(&vm->arena[cursor->pos + 1], 2);
	value = (value < 0 ? IDX_MOD + value : value % IDX_MOD);
	value += cursor->pos % MEM_SIZE;
	return (value);
}

static void	cp_regs(t_cursor *new, int32_t reg[16])
{
	int		i;

	i = 0;
	while (i < REG_NUMBER)
	{
		new->reg[i] = reg[i];
		i++;
	}
}

static void	insert_new(t_cursor *new, t_vm *vm)
{
	t_cursor	*curr;
	t_cursor	*temp;

	curr = vm->cursor;
	while (curr)
	{
		if (curr->id == new->id)
		{
			temp = curr->next;
			curr->next = new;
			new->next = temp;
		}
		curr = curr->next;
	}
}

bool		op_fork(t_cursor *cursor, t_vm *vm)
{
	int			new_pos;
	t_cursor	*new;

	if (cursor && vm)
	{	
		new_pos = get_value(vm, cursor);
		new = init_cursor(cursor->id, new_pos, cursor->opcode, 0);
		cp_regs(new, cursor->reg);
		insert_new(new, vm);
		vm->process++;
		ft_printf("value %d\n", new_pos);
		return (true);
	}
	return (false);
}
