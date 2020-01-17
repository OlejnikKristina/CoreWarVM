/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_players.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 19:59:32 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/17 19:08:04 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm_arena.h"

bool	get_player_comment(t_player *player, const int fd)
{
	char	player_comment[COMMENT_LENGTH + 1];

	ft_bzero(player_comment, COMMENT_LENGTH + 1);
	if (read(fd, player_comment, COMMENT_LENGTH) >= COMMENT_LENGTH)
	{
		player->comment = ft_strdup(player_comment);
		return (true);
	}
	return (false);
}

bool	get_player_name(t_player *player, const int fd)
{
	char	player_name[PROG_NAME_LENGTH + 1];

	ft_bzero(player_name, PROG_NAME_LENGTH + 1);
	if (read(fd, player_name, PROG_NAME_LENGTH) >= PROG_NAME_LENGTH)
	{
		player->name = ft_strdup(player_name);
		return (true);
	}
	return (false);
}

/*
** Magic header is a signature of the file and means
** file is of a certain type (make analogy to the extension).
*/

bool	is_magic_header(const int fd)
{
	uint32_t	magic_number_input;
	uint32_t	magic_number_reference;
	uint8_t		*m_in;
	uint8_t		*m_ref;

	if (read(fd, &magic_number_input, 4) < 4)
		return (false);
	magic_number_reference = COREWAR_EXEC_MAGIC;
	m_in = (uint8_t *)&magic_number_input;
	m_ref = (uint8_t *)&magic_number_reference;
	return ((
		m_ref[0] == m_in[0] &&
		m_ref[1] == m_in[1] &&
		m_ref[2] == m_in[2] &&
		m_ref[3] == m_in[3])
		|| (
		m_ref[0] == m_in[3] &&
		m_ref[1] == m_in[2] &&
		m_ref[2] == m_in[1] &&
		m_ref[3] == m_in[0]));
}

bool	init_player(t_player *player, char *player_file)
{
	int		fd;

	fd = open((const char *)player_file, O_RDONLY);
	if (fd <= 0 && error_msg(2))
	{
		ft_printf("[%s]\n", player_file);
		return (false);
	}
	if (!is_magic_header(fd) && error_msg(1))
		return (false);
	if (!get_player_name(player, fd) && error_msg(3))
		return (false);
	if (!check_null_byte(fd) && error_msg(4))
		return (false);
	if (!get_player_code_size(player, fd) && error_msg(7))
		return (false);
	if (!get_player_comment(player, fd) && error_msg(6))
		return (false);
	if (!check_null_byte(fd) && error_msg(4))
		return (false);
	if (!get_player_exec_code(player, fd) && error_msg(8))
		return (false);
	player->last_live = 0;
	player->lives = 0;
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
	vm->players = (t_player **)ft_memalloc(sizeof(t_player *) *
	(vm->players_amnt));
	if (!vm->players)
		return (0);
	while (i < vm->players_amnt)
	{
		if (!(vm->players[i] = (t_player *)ft_memalloc(sizeof(t_player))))
			return (0);
		set_player_id(vm->players[i], vm->flag->players_order, i,
		vm->players_amnt);
		if (!init_player(vm->players[i], players_files[i]))
			return (false);
		i++;
	}
	if (!vm->flag->v && !vm->flag->dump)
		introduce_champions(vm->players, vm->players_amnt, 1);
	if (vm->flag->dump)
		introduce_champions(vm->players, vm->players_amnt, 0);
	return (true);
}
