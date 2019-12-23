/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_chempion.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 17:12:32 by krioliin       #+#    #+#                */
/*   Updated: 2019/12/23 17:57:23 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm_arena.h"

void	set_player_id(t_player *player, short players_order[MAX_PLAYERS],
		short num)
{
	int		i;
	int		id;
	int		choosen_id;

	i = 0;
	choosen_id = 1;
	id = players_order[num];
	if (id == -1)
	{
		while (id == -1 && i < MAX_PLAYERS)
		{
			if (choosen_id == players_order[i])
			{
				i = -1;
				choosen_id++;
			}
			i++;
		}
		players_order[num] = choosen_id;
		player->id = choosen_id;
	}
	else
		player->id = id;
}

bool	check_null_byte(const int fd)
{
	uint32_t	null_byte;
	uint8_t		*null_byte_ref;

	if ((read(fd, &null_byte, 4) <= 4))
	{
		null_byte_ref = (uint8_t *)&null_byte;
		return (
		null_byte_ref[0] == 0 &&
		null_byte_ref[1] == 0 &&
		null_byte_ref[2] == 0 &&
		null_byte_ref[3] == 0);
	}
	return (false);
}

bool	get_player_code_size(t_player *player, const int fd)
{
	uint32_t	code_size;
	uint8_t		*code_size_ref;

	if (read(fd, &code_size, 4) < 4 && player)
		return (false);
	code_size_ref = (uint8_t *)&code_size;
	ft_printf("[%x][%x][%x][%x]\n",
	code_size_ref[0], code_size_ref[1],
	code_size_ref[2], code_size_ref[3]);
	return (true);
}
