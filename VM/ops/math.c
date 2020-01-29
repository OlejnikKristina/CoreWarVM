/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 12:20:25 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/28 16:42:36 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function adds 2 values from regs and puts it into reg a3
**	@param	- t_cursor *c, current cursor
**			- t_args *args, arguments
*/

void	add(t_cursor *c, t_args *args)
{
	t_args	a1;
	t_args	a2;
	t_args	a3;
	int		val;

	a1 = args[0];
	a2 = args[1];
	a3 = args[2];
	val = c->reg[a1.value - 1] + c->reg[a2.value - 1];
	c->reg[a3.value - 1] = val;
	c->carry = (val == 0 ? 1 : 0);
}

/*
**	@desc	- function subtracts 2 values from regs and puts it into reg a3
**	@param	- t_cursor *c, current cursor
**			- t_args *args, arguments
*/

void	sub(t_cursor *c, t_args *args)
{
	t_args	a1;
	t_args	a2;
	t_args	a3;
	int		val;

	a1 = args[0];
	a2 = args[1];
	a3 = args[2];
	val = c->reg[a1.value - 1] - c->reg[a2.value - 1];
	c->reg[a3.value - 1] = val;
	c->carry = (val == 0 ? 1 : 0);
}
