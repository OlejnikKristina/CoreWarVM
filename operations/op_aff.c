/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_aff.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 21:29:05 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/30 21:29:08 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

bool		op_aff(t_cursor *cursor, t_vm *vm)
{
	ft_putchar((char)cursor->reg[vm->arena[((cursor->pos + 1) % MEM_SIZE)]]);
	return (true);
}
