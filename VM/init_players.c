/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_players.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 19:59:32 by krioliin       #+#    #+#                */
/*   Updated: 2019/12/22 21:08:05 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm_arena.h"

void	set_player_id(t_player *player,
		short players_order[MAX_PLAYERS], short num)
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

// bool	get_player_name()
// {
// 	return (true);
// }

int		ft_memcomp(const void *s1, const void *s2, size_t n)
{
	unsigned char *p1;
	unsigned char *p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n)
	{
		if (*(p1++) != *(p2++))
			break ;
		n--;
	}
	return (*(p1 - 1) - *(p2 - 1));
}

/*
** Magic header is a signature of the file and means
** file is of a certain type (make analogy to the extension).
*/

bool	is_magic_header(const int fd)
{
	uint8_t		magic_header[4];
	uint32_t	magic_header2;
	uint32_t	magic;

	magic = COREWAR_EXEC_MAGIC;
	if (read(fd, magic_header, 4) < 4)
	{
		ft_printf("Error. Too small file: ");
		return (false);
	}
	magic_header2 = magic_header[0] | magic_header[1] | magic_header[2] | magic_header[3];
	ft_printf("[%x] ", magic);
	ft_printf("[%x] ", magic_header);
	ft_printf("[%x]\n\n", magic_header2);
	if (ft_memcomp((const void *)magic_header, (const void *)&magic, 4))
	{
		ft_printf("Error. Incorrect magic header. In file: ");
		return (false);
	}
	return (true);
}

bool	init_player(t_player *player, char *player_file)
{
	int		fd;

	fd = open((const char *)player_file, O_RDONLY);
	if (fd <= 0 && player)
	{
		ft_printf("%{RED_B}Can't read file [%s]%{RESET}\n", player_file);
		return (false);
	}
	ft_printf("file [%s]%{RESET}\n", player_file);
	if (!is_magic_header(fd) && ft_printf("%s\n", player_file))
		return (false);
	// get_player_name(player, fd);
	close(fd);
	return (true);
}

bool	init_players(t_vm *vm)
{
	int		i;
	char	**players_files;

	i = 0;
	vm->players_amnt = get_players_amnt(0);
	players_files = safe_players_files(NULL);
	vm->players = (t_player **)ft_memalloc(sizeof(t_player *) * (vm->players_amnt));
	if (!vm->players)
		return (0);
	while (i < vm->players_amnt)
	{
		if (!(vm->players[i] = (t_player *)ft_memalloc(sizeof(t_player))))
			return (0);
		set_player_id(vm->players[i], vm->flag->players_order, i);
		init_player(vm->players[i], players_files[i]);
		i++;
	}
	return (true);
}
