/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_champion.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 17:12:32 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/10 14:24:00 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm_arena.h"

void		set_start_pos(t_player *player, int id, short players_amnt)
{
	int	abs_id;
	int	space;

	abs_id = (id < 0 ? id * -1 : id);
	abs_id--;
	space = MEM_SIZE / (int)players_amnt;
	player->start_pos = space * abs_id;
}

void		set_player_id(t_player *player, short players_order[MAX_PLAYERS],
		short num, short players_amnt)
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
	set_start_pos(player, player->id, players_amnt);
}

bool		check_null_byte(const int fd)
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

uint32_t	reverse_bytes(uint32_t in)
{
	uint32_t	res;
	uint8_t		*res_bytes;
	uint8_t		*in_bytes;

	res = 0;
	res_bytes = (uint8_t *)&res;
	in_bytes = (uint8_t *)&in;
	res_bytes[0] = in_bytes[3];
	res_bytes[1] = in_bytes[2];
	res_bytes[2] = in_bytes[1];
	res_bytes[3] = in_bytes[0];
	return (res);
}

bool		get_player_code_size(t_player *player, const int fd)
{
	uint32_t num;

	if (read(fd, &num, 4) < 4)
		return (false);
	num = reverse_bytes(num);
	if (CHAMP_MAX_SIZE < num)
		return (false);
	player->code_size = (int)num;
	return (true);
}
