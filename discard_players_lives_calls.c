/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   discard_players_lives_calls.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/18 16:32:17 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/25 20:05:43 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

void	discard_players_lives_calls(t_vm *vm)
{
	short index;

	index = 0;
	while (index < vm->players_amnt)
	{
		vm->players[index]->lives = 0;
		vm->players[index]->last_live = 0;
		if (vm->flag->v)
			display_live_calls(vm->v->winfo, vm->players[index], 0);
		index++;
	}
}
