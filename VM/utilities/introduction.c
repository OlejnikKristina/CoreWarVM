/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   introduction.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/27 17:36:54 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/15 16:05:40 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

void	introduce_champion(t_player *player)
{
	ft_printf("%{WHITE_B}* Player %d, ", player->id);
	ft_printf("weighing %{BLUE_B}%u%{WHITE_B}, ",
	(unsigned int)player->code_size);
	ft_printf("\"%{PINK_B}%s%{WHITE_B}\" ", player->name);
	ft_printf("(\"%{GREEN_B}%s%{WHITE_B}\") !\n%{RESET}", player->comment);
}

void	introduce_champions(t_player **players, short player_amnt)
{
	short	i;
	short	player_id;

	i = 0;
	player_id = 1;
	ft_printf("Introducing contestants...\n");
	while (player_id <= player_amnt)
	{
		if (players[i]->id == player_id)
		{
			introduce_champion(players[i]);
			player_id++;
			i = -1;
		}
		i++;
	}
}
