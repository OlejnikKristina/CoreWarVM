/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   encode_match_opcode.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 18:54:48 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/06 15:15:23 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

bool	en_op_code_add_sub(e_argctype arg_type[3])
{
	return (
	(arg_type[0] == REG) &&
	(arg_type[1] == REG) &&
	(arg_type[2] == REG));
}

bool	en_op_code_st(e_argctype arg_type[3])
{
	return (
	(arg_type[0] == REG) &&
	(arg_type[1] == REG || arg_type[1] == IND) &&
	(arg_type[2] == 0));
}

bool	en_op_code_ld_lld(e_argctype arg_type[3])
{
	return (
	(arg_type[0] == DIR || arg_type[0] == IND) &&
	(arg_type[1] == REG) &&
	(arg_type[2] == 0));
}

void	init_op_encode_validation_arr(bool (*op_encode[17])(e_argctype *))
{
	op_encode[1] = NULL;
	op_encode[2] = en_op_code_ld_lld;
	op_encode[3] = en_op_code_st;
	op_encode[4] = en_op_code_add_sub;
	op_encode[5] = en_op_code_add_sub;
	op_encode[6] = en_op_code_and_or_xor;
	op_encode[7] = en_op_code_and_or_xor;
	op_encode[8] = en_op_code_and_or_xor;
	op_encode[9] = NULL;
	op_encode[10] = en_op_code_ldi_lldi;
	op_encode[11] = en_op_code_sti;
	op_encode[12] = NULL;
	op_encode[13] = en_op_code_ld_lld;
	op_encode[14] = en_op_code_ldi_lldi;
	op_encode[15] = NULL;
	op_encode[16] = en_op_code_aff;
}
