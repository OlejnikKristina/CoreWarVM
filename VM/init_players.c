/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_players.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 19:59:32 by krioliin       #+#    #+#                */
/*   Updated: 2019/12/22 16:46:00 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm_arena.h"

bool	init_player(t_player *player, char *player_file, short id)
{
	static int	last_free_id;
	int			fd;

	fd = open((const char *)player_file, O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("%{RED_B}Can't read file [%s]%{RESET}\n", player_file);
		return (false);
	}
	if (id == -1)
		player->id = ++last_free_id;
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
		init_player(vm->players[i], players_files[i], vm->flag->players_order[i]);
		i++;
	}
	ft_printf("N: %d\n", vm->players[0]->id);
	ft_printf("N: %d\n", vm->players[1]->id);
	ft_printf("N: %d\n", vm->players[2]->id);
	ft_printf("N: %d\n", vm->players[3]->id);
	ft_printf("Players amount: %d\n", vm->players_amnt);
	safe_players_files("free it");
	return (true);
}
