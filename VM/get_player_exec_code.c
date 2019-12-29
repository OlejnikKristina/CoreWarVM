/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_player_exec_code.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/27 18:19:50 by krioliin       #+#    #+#                */
/*   Updated: 2019/12/29 14:02:50 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm_arena.h"
#include "includes/t_dir_sizes.h"

/* Returns a t_dir size according to opcode */

short	get_dir_size(uint8_t opcode)
{
	return
	(( opcode == ZJMP || opcode == LDI
	|| opcode == FORK || opcode == STI
	|| opcode == LLDI || opcode == LFORK)
	? 2 : 4);
}

/*
**	add_bytes_to_pc - calc amount of bytes need to program_counter
**	according to instruction (live,sti,ld...)
**	and diffirent arguments type (REG|DIR|IND)
*/

short	add_bytes_to_pc(e_argctype arg_type, uint8_t opcode)
{
	if (arg_type == DIR)
		return (get_dir_size(opcode));
	return (arg_type);
}

/*
**	Calculate and return amount of bytes to next instruction.
*/

int		calculate_program_counter(uint8_t opcode, unsigned char encod_byte)
{
	int				program_counter;
	char			res;
	e_argctype		argc_type[3];

	program_counter = 0;
	if (is_encoding_byte(opcode) && encod_byte)
	{
		ft_printf("opcode (%d)\n", opcode);
		decode_encoding_byte(encod_byte, argc_type);
		program_counter += add_bytes_to_pc(argc_type[0], opcode);
		program_counter += add_bytes_to_pc(argc_type[1], opcode);
		program_counter += add_bytes_to_pc(argc_type[2], opcode);
		program_counter += 2;
		ft_printf("type: [%d] [%d] [%d]\n", argc_type[0], argc_type[1], argc_type[2]);
		ft_printf("program_counter: %d\n", program_counter);
	}
	else
	{
		res = 1;
	}
	return (program_counter);
}

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
