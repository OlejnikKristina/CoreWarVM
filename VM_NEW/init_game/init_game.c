/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:38:16 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/28 16:13:00 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- initializes cursor
**	@param	- t_vm *vm, main struct
*/

static void	set_cursors(t_vm *vm)
{
	int		i;
	t_champ	champ;

	i = 0;
	while (i < NB_PLAYERS)
	{
		champ = CHAMPS[i];
		add_cursor(&CURSORS,
		new_cursor(champ.start_pos, champ.id * -1, GAME->cursors_id));
		GAME->cursors_id++;
		i++;
	}
}

/*
**	@desc	- function introduces champions
**	@param	- t_champ *champs, champs to introduce
**			- int nb_champs, number of champs
*/

static void	intro_champs(t_champ *champs, int nb_champs)
{
	int	i;

	i = 0;
	ft_putendl("Introducing contestants...");
	while (i < nb_champs)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		champs[i].id, champs[i].size, champs[i].name, champs[i].comment);
		i++;
	}
}

/*
**	@desc	- function initializes the game field
**	@param	- t_vm *vm, main struct
*/

void		init_game(t_vm *vm)
{
	GAME = (t_game*)ft_memalloc(sizeof(t_game));
	GAME->last_live = NB_PLAYERS;
	GAME->cycles_to_die = CYCLE_TO_DIE;
	GAME->cursors_id = 1;
	GAME->processes = NB_PLAYERS;
	set_cursors(vm);
	intro_champs(CHAMPS, NB_PLAYERS);
}
