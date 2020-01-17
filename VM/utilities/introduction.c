/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   introduction.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/27 17:36:54 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/17 15:09:16 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

static void	intro_plain(t_player *player)
{
	ft_printf("* Player %d, ", player->id);
	ft_printf("weighing %u bytes, ",
	(unsigned int)player->code_size);
	ft_printf("\"%s\" ", player->name);
	ft_printf("(\"%s\") !\n", player->comment);
}

void		introduce_champion(t_player *player, int colour)
{
	if (!colour)
	{
		intro_plain(player);
		return ;
	}
	ft_printf("%{WHITE_B}* Player %d, ", player->id);
	ft_printf("weighing %{BLUE_B}%u bytes%{WHITE_B}, ",
	(unsigned int)player->code_size);
	ft_printf("\"%{PINK_B}%s%{WHITE_B}\" ", player->name);
	ft_printf("(\"%{GREEN_B}%s%{WHITE_B}\") !\n%{RESET}", player->comment);
}

void		introduce_champions(t_player **players, short player_amnt, int colour)
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
			introduce_champion(players[i], colour);
			player_id++;
			i = -1;
		}
		i++;
	}
}
