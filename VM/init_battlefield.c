/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_battlefield.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 18:47:21 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/08 20:15:51 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

void	put_player_on_arena(uint8_t arena[MEM_SIZE], t_player *player,
		int start_pos)
{
	int		i;

	i = 0;
	while (i < player->code_size)
	{
		arena[start_pos] = player->code[i];
		start_pos++;
		i++;
	}
}

bool	init_battlefield(t_vm *vm)
{
	int		player_pos;
	int		i;

	i = 0;
	ft_bzero(vm->arena, MEM_SIZE);
	player_pos = 0;
	while (i < vm->players_amnt)
	{
		put_player_on_arena(vm->arena,
		get_player_by_id(vm->players, i + 1, vm->players_amnt), player_pos);
		player_pos += MEM_SIZE / vm->players_amnt;
		i++;
	}
	return (true);
}
