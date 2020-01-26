/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_game.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 17:27:58 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/26 18:43:26 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function kills dead cursors and returns amount it killed
**	@param	- t_vm *vm, main struct
**			- int cycles, cycles passed in current period
**	@return	- 0 to reset cycles
*/

static void	check_live(t_vm *vm, int cycles)
{
	t_cursor	*curr;
	t_cursor	*temp;

	curr = CURSORS;
	while (curr)
	{
		temp = curr->next;
		if (GAME->cycles_to_die < 1
		|| curr->last_live <= (GAME->cycles - cycles))
		{
			CURSORS = rm_cursor(CURSORS, curr->id);
			GAME->processes--;
		}
		curr = temp;
	}
}

/*
**	@desc	- funtion checks if there are still processes alive
**	@param	- t_vm *vm, main struct
**			- int cycles, 
**	@return	- 1 if still processes, 0 if not
*/

static int	check(t_vm *vm, int cycles)
{
	GAME->checks++;
	check_live(vm, cycles);
	if (NBR_LIVE <= GAME->lives || MAX_CHECKS <= GAME->checks)
	{
		GAME->cycles_to_die -= CYCLE_DELTA;
		GAME->checks = 0;
	}
	GAME->lives = 0;
	return (0);
}

/*
**	@desc	- function starts and ends the game
**	@param	- t_vm *vm, main struct
*/

void		start_game(t_vm *vm)
{
	int		cycles;

	cycles = 0;
	while (CURSORS)
	{
		if (!FLAG->v && FLAG->dump == GAME->cycles)
			dump64(vm);
		cycles++;
		GAME->cycles++;
		execute(vm);
		if (GAME->cycles_to_die < 1 || cycles == GAME->cycles_to_die)
			cycles = check(vm, cycles);
	}
	ft_printf("Contestant %d, \"%s\", has won !\n",
	GAME->winner, CHAMPS[GAME->winner - 1].name);
}
