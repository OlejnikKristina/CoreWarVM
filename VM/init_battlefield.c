/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_battlefield.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 18:47:21 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/02 16:50:57 by krioliin      ########   odam.nl         */
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

// static void	display_arena(uint8_t arena[MEM_SIZE])
// {
// 	int		i;

// 	i = 0;
// 	while (i < MEM_SIZE - 1)
// 	{
// 		if (i == 0)
// 		 ft_printf(" 0");
// 		if (arena[i] == 0)
// 			ft_printf("%x ", arena[i]);
// 		else
// 			ft_printf("%{YELLOW_B}%x%{RESET} ", arena[i]);
// 		if (i % 50 == 0 && i != 0)
// 			ft_printf("\n ");
// 		i++;
// 	}
// }

bool	init_battlefield(t_vm *vm)
{
	int		player_pos;
	int		i;

	i = 0;
	ft_bzero(vm->arena, MEM_SIZE);
	player_pos = 0;
	while (i < vm->players_amnt)
	{
		put_player_on_arena(vm->arena, vm->players[i], player_pos);
		player_pos += MEM_SIZE / vm->players_amnt;
		i++;
	}
	// display_arena(vm->arena);
	return (true);
}
