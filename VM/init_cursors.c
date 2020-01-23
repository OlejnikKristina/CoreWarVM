/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_cursors.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 16:33:33 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/23 13:21:39 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vm_arena.h"

t_cursor	*init_cursor(int id, int pos, int opcode, int encoding_byte)
{
	t_cursor	*cursor;

	if (!(cursor = (t_cursor *)ft_memalloc(sizeof(t_cursor))))
		return (NULL);
	cursor->id = id;
	cursor->pos = pos;
	cursor->opcode = opcode;
	cursor->pc = calculate_program_counter(opcode, encoding_byte);
	cursor->wait_cycles = get_waite_cycle(opcode);
	cursor->reg[0] = id * -1;
	cursor->prev_xy[0] = -1;
	cursor->prev_xy[1] = -1;
	return (cursor);
}

bool		init_cursors(t_vm *vm)
{
	t_cursor	*current;
	short		id;
	int			pos;

	id = vm->players_amnt;
	vm->process = vm->players_amnt;
	pos = MEM_SIZE - MEM_SIZE / vm->players_amnt;
	if (MEM_SIZE % vm->players_amnt)
		pos--;
	vm->cursor = init_cursor(id, pos, vm->arena[pos], vm->arena[pos + 1]);
	current = vm->cursor;
	id--;
	while (id)
	{
		pos -= MEM_SIZE / vm->players_amnt;
		current->next = init_cursor(id, pos, vm->arena[pos],
						vm->arena[pos + 1]);
		current = current->next;
		id--;
	}
	current->next = NULL;
	return (true);
}
