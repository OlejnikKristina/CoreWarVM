/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate_program_counter.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/29 14:13:56 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/07 14:50:18 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"
#include "operations.h"

/* Returns a t_dir size according to opcode */

short	get_dir_size(uint8_t opcode)
{
	return
	(( opcode == ZJMP || opcode == LDI
	|| opcode == FORK || opcode == STI
	|| opcode == LLDI || opcode == LFORK)
	? 2 : 4);
}

bool	is_encoding_byte(uint8_t opcode)
{
	return (
		opcode != LIVE && opcode != ZJMP &&
		opcode != FORK && opcode != LFORK);
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
	else if (arg_type == IND)
		return (2);
	else if (arg_type == REG)
		return (1);
	return (0);
}

/*
**	Calculate and return amount of bytes to next instruction.
*/

int		calculate_program_counter(uint8_t opcode, uint8_t encod_byte)
{
	int			program_counter;
	e_argctype	argc_type[3];

	program_counter = 0;
	if (is_encoding_byte(opcode))
	{
		// ft_printf("opcode (%d)\n", opcode);
		decode_encoding_byte(encod_byte, argc_type);
		program_counter += add_bytes_to_pc(argc_type[0], opcode);
		program_counter += add_bytes_to_pc(argc_type[1], opcode);
		program_counter += add_bytes_to_pc(argc_type[2], opcode);
		// ft_printf("type: [%d] [%d] [%d]\n", argc_type[0], argc_type[1], argc_type[2]);
		return (program_counter + 2);
	}
	else if (opcode == LIVE)
		program_counter = 4;
	else if (opcode == ZJMP || opcode == FORK || opcode == LFORK)
		program_counter = 2;
	return (program_counter + 1);
}
