/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_player_exec_code.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/27 18:19:50 by krioliin       #+#    #+#                */
/*   Updated: 2019/12/28 14:59:38 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm_arena.h"

//zork's exec code
//0b 68 01 00 0f 00 01 06 64 01 00 00 00 00 01 01 00 00 00 01 09 ff fb
//68 = 01 10 10 00 [T_REG|T_DIR|T_DIR]

int		calculate_jump(uint8_t opcode, uint8_t codage_octet)
{
	ft_printf("[]");
	return (0);
}

bool	check_player_exec_code(uint8_t *code, int code_size)
{
	int		jump;
	uint8_t	opcode;
	int		i;

	i = 0;
	jump = 0;

	opcode = code[i];
	calculate_jump(code[i], code[i + 1]);
	// while (i < code_size)
	// {
	// 	i++;
	// }
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
