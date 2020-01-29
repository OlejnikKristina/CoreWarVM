/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_args.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 19:20:26 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/28 16:39:18 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function gets opcode for cursor
**	@param	- t_byte opcode, opcode to read
**			- t_cursor *c, current cursor
*/

void			opcode(t_byte opcode, t_cursor *c)
{
	c->moved = 0;
	c->opcode = opcode;
	if (opcode > 0 && NB_OPS >= opcode)
		c->wait_cycles = g_op_tab[opcode].cycle;
	else
		c->wait_cycles = 0;
}

/*
**	@desc	- function gets single argument
**	@param	- int opcode, operation code
**			- t_byte type, type of the argument
**	@return	- t_args arg, single argument struct
*/

static t_args	get_arg(int opcode, t_byte type)
{
	t_args	arg;

	if ((type & 3) == T_REG)
	{
		arg.size = 1;
		arg.type = T_REG;
		return (arg);
	}
	else if ((type & 3) == T_DIR)
	{
		arg.size = g_op_tab[opcode].dir_size;
		arg.type = T_DIR;
		return (arg);
	}
	else
	{
		arg.size = 2;
		arg.type = T_IND;
		return (arg);
	}
}

/*
**	@desc	- function get all arguments for operation
**	@param	- t_cursor *c, current cursor
**			- int octal, octal
**			- t_byte *arena, the arena to read from
**	@return	- t_args *args, t_args struct with value and shit
*/

t_args			*get_args(t_cursor *c, t_byte octal, t_byte *arena)
{
	int		i;
	int		shift;
	int		op_i;
	t_args	*args;

	op_i = 2;
	shift = 6;
	i = 0;
	args = (t_args*)ft_memalloc(sizeof(t_args) * g_op_tab[c->opcode].nb_arg);
	while (i < g_op_tab[c->opcode].nb_arg)
	{
		args[i] = get_arg(c->opcode, ((octal >> shift) & 3));
		args[i].value = get_bytes(arena, get_index(c->pos, op_i),\
		args[i].size);
		shift -= 2;
		op_i += args[i].size;
		i++;
	}
	return (args);
}
