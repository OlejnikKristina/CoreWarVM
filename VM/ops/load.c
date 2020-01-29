/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 12:20:54 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/26 17:21:59 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function loads value into cursor registry
**	@param	- t_vm *vm, main struct
**			- t_cursor *c, current cursor
**			- t_args *args, arguments
*/

void	ld(t_vm *vm, t_cursor *c, t_args *args)
{
	t_args	a1;
	int		reg_nb;

	a1 = args[0];
	reg_nb = args[1].value - 1;
	if (a1.type == T_IND)
		c->reg[reg_nb] = get_bytes(ARENA, get_index(c->pos,
		(a1.value % IDX_MOD)), 4);
	else if (a1.type == T_DIR)
		c->reg[reg_nb] = a1.value;
	c->carry = (c->reg[reg_nb] == 0 ? 1 : 0);
}

/*
**	@desc	- function saves value into reg that was 3rd argument
**	@param	- t_vm *vm, main struct
**			- t_cursor *c, current cursor
**			- t_args *args, arguments
*/

void	ldi(t_vm *vm, t_cursor *c, t_args *args)
{
	int		temp[2];
	int		i;
	int		reg_nb;

	reg_nb = args[2].value - 1;
	i = 0;
	while (i < 2)
	{
		if (args[i].type == T_REG)
			temp[i] = c->reg[args[i].value - 1];
		if (args[i].type == T_DIR)
			temp[i] = args[i].value;
		if (args[i].type == T_IND)
			temp[i] = get_bytes(ARENA, get_index(c->pos,
			args[i].value % IDX_MOD), 4);
		i++;
	}
	c->reg[reg_nb] = get_bytes(ARENA,
	get_index(c->pos, (temp[0] + temp[1]) % IDX_MOD), 4);
}

/*
**	@desc	- more powerful ld
**	@param	- t_vm *vm, main struct
**			- t_cursor, current cursor
**			- t_args *args, arguments
*/

void	lld(t_vm *vm, t_cursor *c, t_args *args)
{
	int		reg_nb;
	t_args	a1;

	a1 = args[0];
	reg_nb = args[1].value - 1;
	if (a1.type == T_IND)
		c->reg[reg_nb] = get_bytes(ARENA, get_index(c->pos, a1.value), 4);
	else if (a1.type == T_DIR)
		c->reg[reg_nb] = a1.value;
	c->carry = (c->reg[reg_nb] == 0 ? 1 : 0);
}

/*
**	@desc	- more powerful ldi
**	@param	- t_vm *vm, main struct
**			- t_cursor, current cursor
**			- t_args *args, arguments
*/

void	lldi(t_vm *vm, t_cursor *c, t_args *args)
{
	int		i;
	int		temp[2];
	int		reg_nb;

	i = 0;
	reg_nb = args[2].value - 1;
	while (i < 2)
	{
		if (args[i].type == T_REG)
			temp[i] = c->reg[args[i].value - 1];
		if (args[i].type == T_DIR)
			temp[i] = args[i].value;
		if (args[i].type == T_IND)
			temp[i] = get_bytes(ARENA, get_index(c->pos,
			args[i].value % IDX_MOD), 4);
		i++;
	}
	c->reg[reg_nb] = get_bytes(ARENA,
	get_index(c->pos, (temp[0] + temp[1]) % MEM_SIZE), 4);
}
