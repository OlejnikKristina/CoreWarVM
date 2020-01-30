/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_lfork.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 14:12:28 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/23 14:52:37 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

static int	get_value(t_vm *vm, int position)
{
	int		value;

	value = convert(&vm->arena[(position + 1) % MEM_SIZE], 2);
	value += position;
	value = (value < 0 ? MEM_SIZE + value : value);
	while (MEM_SIZE <= value)
		value -= MEM_SIZE;
	return (value % MEM_SIZE);
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
	new->next = vm->cursor;
	vm->cursor = new;
}

bool		op_lfork(t_cursor *cursor, t_vm *vm)
{
	int			new_pc;
	t_cursor	*new;

	new_pc = get_value(vm, cursor->pos);
	new = init_cursor(cursor->id, new_pc, cursor->opcode, 0);
	new->last_live = cursor->last_live;
	new->carry = cursor->carry;
	cp_regs(new, cursor->reg);
	insert_new(new, vm);
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
