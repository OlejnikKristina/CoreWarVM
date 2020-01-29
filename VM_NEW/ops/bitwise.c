/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bitwise.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 12:20:52 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/28 16:41:32 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function performs AND operation for values ​​of first 2 args
**			and writes the result into the reg passed as the 3rd arg
**	@param	- t_vm *vm, main struct
**			- t_cursor *c, current cursor
**			- t_args *args, arguments
*/

void	and(t_vm *vm, t_cursor *c, t_args *args)
{
	int i;
	int val;
	int temp[2];

	i = 0;
	while (i < 2)
	{
		if (args[i].type == T_REG)
			temp[i] = c->reg[args[i].value - 1];
		if (args[i].type == T_DIR)
			temp[i] = args[i].value;
		if (args[i].type == T_IND)
			temp[i] = get_bytes(ARENA,
			get_index(c->pos, (args[i].value % IDX_MOD)), 4);
		i++;
	}
	val = temp[0] & temp[1];
	c->reg[args[2].value - 1] = val;
	c->carry = (val == 0 ? 1 : 0);
}

/*
**	@desc	- function performs OR operation for values ​​of first 2 args
**				and writes the result into the reg passed as the 3rd arg
**	@param	- t_vm *vm, main struct
**			- t_cursor *c, current cursor
**			- t_args *args, arguments
*/

void	or(t_vm *vm, t_cursor *c, t_args *args)
{
	int i;
	int val;
	int temp[2];

	i = 0;
	while (i < 2)
	{
		if (args[i].type == T_REG)
			temp[i] = c->reg[args[i].value - 1];
		if (args[i].type == T_DIR)
			temp[i] = args[i].value;
		if (args[i].type == T_IND)
			temp[i] = get_bytes(ARENA,
			get_index(c->pos, (args[i].value % IDX_MOD)), 4);
		i++;
	}
	val = temp[0] | temp[1];
	c->reg[args[2].value - 1] = val;
	c->carry = (val == 0 ? 1 : 0);
}

/*
**	@desc	- function performs OR operation for values ​​of first 2 args
**			and writes the result into the reg passed as the 3rd arg
**	@param	- t_vm *vm, main struct
**			- t_cursor *c, current cursor
**			- t_args *args, arguments
*/

void	xor(t_vm *vm, t_cursor *c, t_args *args)
{
	int i;
	int val;
	int temp[2];

	i = 0;
	while (i < 2)
	{
		if (args[i].type == T_REG)
			temp[i] = c->reg[args[i].value - 1];
		if (args[i].type == T_DIR)
			temp[i] = args[i].value;
		if (args[i].type == T_IND)
			temp[i] = get_bytes(ARENA,
			get_index(c->pos, (args[i].value % IDX_MOD)), 4);
		i++;
	}
	val = temp[0] ^ temp[1];
	c->reg[args[2].value - 1] = val;
	c->carry = (val == 0 ? 1 : 0);
}
