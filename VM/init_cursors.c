/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_cursors.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 16:33:33 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/17 19:06:51 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vm_arena.h"

void	whats_hide_inside_cursors(t_vm *vm)
{
	t_cursor *cursor;
	t_player *player;

	cursor = vm->cursor;
	while (cursor)
	{
		player = get_player_by_id(vm->players, cursor->reg[0] * -1,
				vm->players_amnt);
		if (!player)
			return ;
		ft_printf("\nCursosr id: %d\n", cursor->id);
		ft_printf("Player id: %d \n", cursor->reg[0]);
		ft_printf("Player name: %s\n", player->name);
		ft_printf("Cursor pos: %d\n", cursor->pos);
		ft_printf("Cursor opcode: %d\n", cursor->opcode);
		ft_printf("Next instruction (pc): %d\n", cursor->pc);
		cursor = cursor->next;
	}
}

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
	// whats_hide_inside_cursors(vm);
	return (true);
}
