/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_player.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 21:16:56 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/02 21:17:30 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_visual.h"

t_player	*get_player(t_player **players, short player_id, short player_amnt)
{
	short	i;

	i = 0;
	while (i < player_amnt)
	{
		if (players[i]->id == player_id)
			return (players[i]);
		i++;
	}
	return (NULL);
}