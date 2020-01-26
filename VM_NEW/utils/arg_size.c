/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_size.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 14:29:46 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/26 16:22:00 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function determines the argument size
**	@param	- int type, type of argument (T_DIR | T_REG | T_IND)
**			- int opcode, operation code
**	@return	- int size, size of the argument
*/

int		arg_size(int type, int opcode)
{
	int	size;

	if (type == T_DIR)
		size = g_op_tab[opcode].dir_size;
	else if (type == T_IND)
		size = 2;
	else if (type == T_REG)
		size = 1;
	else
		size = 0;
	return (size);
}
