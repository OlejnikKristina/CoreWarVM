/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_cursors.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 16:33:33 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/04 18:59:43 by krioliin      ########   odam.nl         */
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
		player = get_player_by_id(vm->players, cursor->reg[0][0] * -1,
				vm->players_amnt);
		if (!player)
			return ;
		ft_printf("\nCursosr id: %d\n", cursor->id);
		ft_printf("Player id: %d \n", cursor->reg[0][0]);
		ft_printf("Player name: %s\n", player->name);
		ft_printf("Cursor pos: %d\n", cursor->position);
		ft_printf("Cursor opcode: %d\n", cursor->opcode);
		ft_printf("Next instruction (pc): %d\n", cursor->pc);
		cursor = cursor->next;
	}
}

t_cursor	*init_cursor(int id, int pos, uint8_t opcode, uint8_t encoding_byte)
{
	t_cursor	*cursor;

	if (!(cursor = (t_cursor *)ft_memalloc(sizeof(t_cursor))))
		return (NULL);
	// ft_bzero(cursor->reg, sizeof(int16_t) * REG_NUMBER * REG_SIZE);
	cursor->id = id;
	cursor->position = pos;
	cursor->opcode = opcode;
	cursor->pc = calculate_program_counter(opcode, encoding_byte);
	cursor->reg[0][0] = id * -1;
	return (cursor);
}

bool		init_cursors(t_vm *vm)
{
	t_cursor	*current;
	short		id;
	int			pos;

	id = vm->players_amnt;
	pos = MEM_SIZE - (MEM_SIZE / vm->players_amnt);
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
	// if (vm->flags->v)
	// 	vs_init_cursor(vm->cursor);
	whats_hide_inside_cursors(vm);
	return (true);
}