/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 15:26:21 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/12 19:08:43 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"


// static void	displ_cursors(t_cursor *cursors, uint8_t arena[MEM_SIZE],
// 			short players_amnt)
// {
// 	t_cursor	*cursor;
// 	int			next_player;
// 	int			y;
// 	int			x;
// 	int			i;

// 	// next_player = MEM_SIZE;
// 	i = players_amnt - 1;
// 	cursor = cursors;
// 	if (arena)
// 		;
// 	while (cursor)
// 	{
// 		next_player = ((HEIGHT) / players_amnt) * i;
// 		x = cursor->pos - (MEM_SIZE / players_amnt) * i;
// 		if (64 <= x)
// 		{
// 			y = x % 64;
// 			x %= 64;
// 		}
// 		else
// 			y = 1;
// 		cursor = cursor->next;
// 		i--;
// 	}
// }

void	init_vm(t_vm *vm)
{
	vm->process = vm->players_amnt;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->last_alive = vm->players[0]->id;
}

int		main(int argc, char **argv)
{
	t_vm		*vm;

	if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		return (0);
	if (!(vm->flag = (t_flags *)ft_memalloc(sizeof(t_flags))))
		return (0);
	if (!args_validation(argc, argv, vm->flag))
		parse_error();
	else if (!init_players(vm))
		ft_printf("Can't init players\n");
	else if (!init_battlefield(vm))
	{
		vm_free(&vm);
		return (0);
	}
	else if (!init_cursors(vm))
		ft_printf("Error in cursor init\n");
	else
	{
		init_vm(vm);
		// displ_cursors(vm->cursor, vm->arena, vm->players_amnt);
		start_game(vm);
	}
	vm_free(&vm);
	return (0);
}
