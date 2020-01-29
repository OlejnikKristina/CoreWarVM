/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   store.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 12:20:58 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/29 15:33:00 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function stores value dest dependent on a2.value
**	@param	- t_vm *vm, main struct
**			- t_cursor *c, current cursor
**			- t_args *args, arguments
*/

void	st(t_vm *vm, t_cursor *c, t_args *args)
{
	int		index;
	int		val;
	t_args	a1;
	t_args	a2;

	a1 = args[0];
	a2 = args[1];
	if (a2.type == T_REG)
		c->reg[a2.value - 1] = c->reg[a1.value - 1];
	else if (a2.type == T_IND)
	{
		val = swap_32(c->reg[a1.value - 1]);
		index = get_index(c->pos, (a2.value % IDX_MOD));
		put_value(ARENA, index, &val);
		if (FLAG->v)
			visual_store(vm->v->warena, vm->arena, c->reg[0] * -1, index);
	}
}

/*
**	@desc	- function writes value from reg that 1st argument
**	@param	- t_vm *vm, main struct
**			- t_cursor *c, current cursor
**			- t_args *args, arguments
*/

void	sti(t_vm *vm, t_cursor *c, t_args *args)
{
	int		temp[3];
	int		i;
	int		index;

	i = 0;
	while (i < 3)
	{
		if (args[i].type == T_REG)
			temp[i] = c->reg[args[i].value - 1];
		if (args[i].type == T_DIR)
			temp[i] = args[i].value;
		if (args[i].type == T_IND)
			temp[i] = get_bytes(ARENA,
			get_index(c->pos, args[i].value % IDX_MOD), 4);
		i++;
	}
	temp[0] = swap_32(temp[0]);
	index = get_index(c->pos, (temp[1] + temp[2]) % IDX_MOD);
	put_value(ARENA, index, &temp[0]);
	if (FLAG->v)
		visual_store(vm->v->warena, vm->arena, c->reg[0] * -1, index);
}
