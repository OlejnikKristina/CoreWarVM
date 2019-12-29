/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   decode_encoding_byte.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/28 18:19:42 by krioliin       #+#    #+#                */
/*   Updated: 2019/12/29 14:42:26 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm_arena.h"
#include "includes/t_dir_sizes.h"

//zork's exec code
//0b 68 01 00 0f 00 01 06 64 01 00 00 00 00 01 01 00 00 00 01 09 ff fb

/*
**	Encoding byte
**	1th fraction 00 00 [10] 00
**	dec(4)  = code(01) = T_REG
**	dec(8)  = code(10) = T_DIR
**	dec(12) = code(11) = T_IND
**
**	2th fraction 00 [10] 00 00
**	dec(16) = code(01) = T_REG
**	dec(32) = code(10) = T_DIR
**	dec(48) = code(11) = T_IND
**
**	3th fraction [01] 00 00 00
**	dec(64)  = code(01) = T_REG
**	dec(128) = code(10) = T_DIR
**	dec(192) = code(11) = T_IND
*/

e_argctype	reg_dir_ind(unsigned char dec_num, short fraction_num)
{
	if (fraction_num == 3)
		return (dec_num / 4);
	else if (fraction_num == 2)
		return (dec_num / 16);
	return (dec_num / 64);
}

/*
** Decode encoding byte
** Extract types of next 3 arguments from encoding_byte
** Applies 3 diffirent masks to get 3 codes
** Transform 3 codes to 3 argument's types and store them in op_args[3]
*/

int		decode_encoding_byte(unsigned char encod_byte, e_argctype op_args[3])
{
	unsigned char	mask[3];
	unsigned char	byte_fr[3];

	ft_bzero(byte_fr, 3);
	mask[0] = 0b11000000;
	mask[1] = 0b00110000;
	mask[2] = 0b00001100;
	byte_fr[0] = mask[0] & encod_byte;
	byte_fr[1] = mask[1] & encod_byte;
	byte_fr[2] = mask[2] & encod_byte;
	ft_printf("mask[0] = dec(%d)\n", byte_fr[0]);
	ft_printf("mask[1] = dec(%d)\n", byte_fr[1]);
	ft_printf("mask[2] = dec(%d)\n", byte_fr[2]);
	op_args[0] = reg_dir_ind(byte_fr[0], 1);
	op_args[1] = reg_dir_ind(byte_fr[1], 2);
	op_args[2] = reg_dir_ind(byte_fr[2], 3);
	return (0);
}
