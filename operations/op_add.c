/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_add.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 14:02:20 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/23 14:03:27 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

static int	get_w_reg(t_vm *vm, t_cursor *cursor)
{
	int		w_reg;
	int		offset;

	offset = 4;
	w_reg = vm->arena[(cursor->pos + offset) % MEM_SIZE] - 1;
	return (w_reg);
}

static	int	get_total(t_vm *vm, t_cursor *cursor)
{
	int		total;
	int		a;
	int		b;

	a = vm->arena[(cursor->pos + 2) % MEM_SIZE] - 1;
	b = vm->arena[(cursor->pos + 3) % MEM_SIZE] - 1;
	total = cursor->reg[a] + cursor->reg[b];
	return (total);
}

bool		op_add(t_cursor *cursor, t_vm *vm)
{
	int	w_reg;
	int	total;

	if (cursor && vm)
	{
		w_reg = get_w_reg(vm, cursor);
		total = get_total(vm, cursor);
		cursor->reg[w_reg] = total;
		cursor->carry = (cursor->reg[w_reg] == 0 ? 1 : 0);
		return (true);
	}
	return (false);
}
