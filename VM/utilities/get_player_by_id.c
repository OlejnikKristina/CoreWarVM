/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_by_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 21:16:56 by krioliin          #+#    #+#             */
/*   Updated: 2020/01/14 18:14:07 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_visual.h"

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