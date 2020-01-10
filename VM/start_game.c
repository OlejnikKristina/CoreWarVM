/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_game.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 15:51:09 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/09 21:42:48 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vm_arena.h"

int		bury_dead_cursors(t_cursor **head)
{
	int			corpse_counter;
	t_cursor	*cursor;
	t_cursor	*prev;

	if (!head || (*head)->last_live == 0)
	{
		ft_memdel((void **)head);
		ft_printf("%{RED}ALL PLAYERS DEAD\n%{RESET}");
		return (100);
	}
	(*head)->last_live = 0;
	corpse_counter = 0;
	prev = *head;
	cursor = (*head)->next;
	while (cursor)
	{
		if (cursor->last_live == 0)
		{
			prev->next = cursor->next;
			ft_memdel((void **)&cursor);
			corpse_counter++;
		}
		cursor->last_live = 0;
		cursor = cursor->next;
		prev = cursor;
	}
	return(corpse_counter);
}

bool		check(t_vm *vm)
{
	static int checks_in_row;

	checks_in_row++;
	if (NBR_LIVE <= vm->nbr_lives || MAX_CHECKS <= checks_in_row)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		checks_in_row = 0;
	}
	vm->nbr_lives = 0;
	vm->process -= bury_dead_cursors(&vm->cursor);
	return (0 < vm->process);
}

bool	execute_one_cycle(t_vm *vm)
{
	t_cursor	*cursor;

	cursor = vm->cursor;
	while (cursor)
	{
		execute_cursor(cursor, vm->arena, vm);
		cursor = cursor->next;
	}
	return (true);
}

bool	up_to_cycle_to_die(t_vm *vm)
{
	bool		someone_alive;
	static int	cycle_counter;

	someone_alive = true;
	while (someone_alive)
	{
		vm->current_cycle = 0;
		while (vm->current_cycle <= vm->cycle_to_die)
		{
			execute_one_cycle(vm);
			cycle_counter++;
			vm->current_cycle += 1;
			// print_arena_pure(vm->arena);
			if (vm->flag->dump == cycle_counter)
				return (show_arena(vm->players, vm->players_amnt, vm));
			// if (vm->flag->dump == 4242)
				// show_arena(vm->players, vm->players_amnt, vm);
			// print_arena_pure(vm->arena);
		}
		someone_alive = check(vm);
	}
	return (true);
}

bool	start_game(t_vm *vm)
{
	t_player *the_champion;

	up_to_cycle_to_die(vm);
	the_champion = get_player_by_id(vm->players, vm->last_alive * -1, vm->players_amnt);
	ft_printf("Contestant %d, \"%s\", has won !\n", vm->last_alive * -1, the_champion->name);
	return (true);
}
