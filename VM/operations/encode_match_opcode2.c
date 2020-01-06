/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   encode_match_opcode2.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 19:29:27 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/06 15:14:48 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

bool	en_op_code_sti(e_argctype arg_type[3])
{
	return (
	(arg_type[0] == REG) &&
	(arg_type[1]) &&
	(arg_type[2] == REG || arg_type[2] == DIR));
}

bool	en_op_code_aff(e_argctype arg_type[3])
{
	return (
	(arg_type[0] == REG) &&
	(arg_type[1] == 0) &&
	(arg_type[2] == 0));
}

bool	en_op_code_ldi(e_argctype arg_type[3])
{
	return (
	(arg_type[0] == REG) &&
	(arg_type[1]) &&
	(arg_type[2] == REG || arg_type[2] == DIR));
}

bool	en_op_code_ldi_lldi(e_argctype arg_type[3])
{
	return (
	(arg_type[0]) &&
	(arg_type[1] == REG || arg_type[1] == DIR) &&
	(arg_type[2] == REG));
}

bool	en_op_code_and_or_xor(e_argctype arg_type[3])
{
	return (
	(arg_type[0]) &&
	(arg_type[1]) &&
	(arg_type[2] == REG));
}
