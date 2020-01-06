/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_player_exec_code.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/27 18:19:50 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/04 17:26:42 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm_arena.h"

bool	is_register_correct(uint8_t *code, uint8_t opcode, int pc)
{

	e_argctype	argc_type[3];
	int			i;

	i = 0;
	decode_encoding_byte(code[pc + 1], argc_type);
	pc += 2;
	while (i < 3)
	{
		// if (argc_type[i] == REG)
		// 	ft_printf("reg [%d] \n", code[pc]);
		if (argc_type[i] == REG && REG_NUMBER < code[pc])
			return (false);
		pc += add_bytes_to_pc(argc_type[i], opcode);
		i++;
	}
	return (true);
}

bool	check_player_exec_code(uint8_t *code, int code_size)
{
	int		pc;

	pc = 0;
	while (pc < code_size)
	{
		if (is_encoding_byte(code[pc]))
		{
			if (!is_register_correct(code, code[pc], pc))
				return (false);
			// ft_printf("program_counter: %d\n", pc);
		}
		pc += calculate_program_counter(code[pc], code[pc + 1]);
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
	// while (i < player->code_size)
	// {
	// 	ft_printf("[%x] ", player->code[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	if (!check_player_exec_code(player->code, player->code_size))
		return (false);
	return (true);
}
