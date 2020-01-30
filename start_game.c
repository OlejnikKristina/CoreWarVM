/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_game.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 20:53:33 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/30 21:28:41 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

bool	check(t_vm *vm)
{
	static int checks_in_row;

	checks_in_row++;
	if (NBR_LIVE <= vm->nbr_lives || MAX_CHECKS <= checks_in_row)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		checks_in_row = 0;
		if (vm->flag->v)
			refresh_cycle_to_die(vm->v->winfo, 29, vm->cycle_to_die);
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
	if (vm->flag->v)
		refresh_arena(vm);
	return (true);
}

bool	up_to_cycle_to_die(t_vm *vm)
{
	bool		someone_alive;

	someone_alive = true;
	while (someone_alive && 0 < vm->cycle_to_die)
	{
		while (vm->current_cycle <= vm->cycle_to_die)
		{
			execute_one_cycle(vm);
			vm->cycle_counter += 1;
			vm->current_cycle += 1;
			if (vm->flag->hexdump == vm->cycle_counter)
				return (show_arena(vm->players, vm->players_amnt, vm));
			else if (vm->flag->dump == vm->cycle_counter)
				return (dump64(vm));
		}
		vm->current_cycle = 0;
		someone_alive = check(vm);
		discard_players_lives_calls(vm);
	}
	return (true);
}

bool	start_game(t_vm *vm)
{
	t_player *winner;

	if (up_to_cycle_to_die(vm))
	{
		winner = get_player_by_id(vm->players, vm->last_alive, vm->players_amnt);
		if (vm->flag->v == true)
			congrats_champion(vm->v->wop, winner);
		else
			ft_printf("Contestant %d, \"%s\", has won !\n",
			vm->last_alive, winner->name);
	}
	return (true);
}
