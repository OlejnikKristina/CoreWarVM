/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   misc.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 12:20:48 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/29 14:48:53 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function reports live for cursor and possibly player
**	@param	- t_vm *vm, main struct
**			- t_cursor *c, current cursor
**			- t_args *args, arguments
*/

void	live(t_vm *vm, t_cursor *c, t_args *args)
{
	args->value = -args->value;
	c->last_live = GAME->cycles;
	if (args->value >= 1 && args->value <= NB_PLAYERS)
	{
		CHAMPS[args->value - 1].lives++;
		CHAMPS[args->value - 1].last_live = c->last_live;
		GAME->last_live = args->value;
		GAME->lives++;
		if (FLAG->v)
			display_live_calls(vm->v->winfo, CHAMPS[args->value - 1], GAME->cycles);
	}
}

/*
**	@desc	- function takes value from reg and prints char value
**	@param	- t_cursor *cursor, current cursor
**			- t_args *args, arguments
*/

void	aff(t_cursor *cursor, t_args *args)
{
	char	c;
	int		reg_nb;

	reg_nb = args[0].value - 1;
	c = (char)cursor->reg[reg_nb];
	write(1, &c, 1);
}
