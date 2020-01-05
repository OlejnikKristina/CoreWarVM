/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_cursor.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 17:28:27 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/05 19:54:13 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vm_arena.h"

short	execute_operation(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	if (cursor)
		;
	return (0);
}

bool	check_opcode(uint8_t opcode)
{
	return (1 <= opcode && opcode <= OP_NBR);
}

bool	check_register(uint8_t	opcode, uint8_t arena[MEM_SIZE])
{
	return (true);
}

bool	check_reg_encodbyte(uint8_t	opcode, uint8_t encoding_byte,
		uint8_t arena[MEM_SIZE])
{
	e_argctype	argc_type[3];
	static bool	(*op_encode[17])(e_argctype *);

	if (!*op_encode[2])
		init_op_encode_validation_arr(op_encode);
	if (is_encoding_byte(opcode))
	{
		decode_encoding_byte(encoding_byte, argc_type);
		if (!(*op_encode[opcode])(argc_type))
			return (false);
	}
	return (true);
}

short	execute_cursor(t_cursor *cursor, uint8_t arena[MEM_SIZE])
{
	if (cursor->wait_cycles == 0)
	{
		if (check_opcode(cursor->opcode))
			cursor->pos += 1;
		else if (
		check_reg_encodbyte(cursor->opcode, arena[cursor->pos + 1], arena))
			execute_operation(cursor, arena);
		else
		{
			cursor->pos += cursor->pc;
			cursor->pc =
			calculate_program_counter(cursor->opcode, arena[cursor->pos + 1]);
		}
		cursor->opcode = arena[cursor->pos];
	}
	else
		cursor->wait_cycles -= 1;
	return (0);
}
