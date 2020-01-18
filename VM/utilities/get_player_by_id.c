/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_player_by_id.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 21:16:56 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/18 16:41:44 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_visual.h"

int			get_player_index(t_player **players, short player_id, short player_amnt)
{
	int	i;

	i = 0;
	if (!player_id)
		return (-1);
	if (player_id < 0)
		player_id = player_id * -1;
	while (i < player_amnt)
	{
		if (players[i]->id == player_id)
			return (i);
		i++;
	}
	return (-1);
}

t_player	*get_player_by_id(t_player **players, short player_id, short player_amnt)
{
	short	i;

	i = 0;
	if (!player_id)
		return (NULL);
	while (i < player_amnt)
	{
		if (players[i]->id == player_id)
			return (players[i]);
		i++;
	}
	return (NULL);
}