/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_player_exec_code.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/27 18:19:50 by krioliin       #+#    #+#                */
/*   Updated: 2019/12/29 14:14:06 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm_arena.h"

bool	check_player_exec_code(uint8_t *code, int code_size)
{
	int		prog_counter;
	int		i;

	i = 0;
	prog_counter = 0;

	prog_counter = calculate_program_counter(code[i], code[i + 1]);
	i += prog_counter;
	prog_counter = calculate_program_counter(code[i], code[i + 1]);
	i += prog_counter;
	prog_counter = calculate_program_counter(code[i], code[i + 1]);
	while (i < code_size)
	{
		i++;
	}
	return (true);
}

bool	get_player_exec_code(t_player *player, const int fd)
{
	int			read_byte;
	int			i;

	i = 0;
	player->code = (uint8_t *)ft_memalloc(player->code_size);
	ft_bzero(player->code, player->code_size);
	read_byte = read(fd, player->code, player->code_size);
	if (read_byte < player->code_size)
		return (false);
	while (i < player->code_size)
	{
		ft_printf("[%x] ", player->code[i]);
		i++;
	}
	ft_printf("\n");
	check_player_exec_code(player->code, player->code_size);
	return (true);
}
