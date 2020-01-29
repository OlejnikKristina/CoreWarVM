/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wait_cycles.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 17:07:47 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/28 16:46:26 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**  @desc   - function gets wait cycles for opcode
**  @param  - int opcode, operation to get wait cycles for
**  @return - nb of wait cycles
*/

int		wait_cycle(int opcode)
{
	if (opcode == LIVE || opcode == ADD || opcode == SUB || opcode == LLD)
		return (10);
	if (opcode == LD || opcode == ST)
		return (5);
	if (opcode == AND || opcode == OR || opcode == XOR)
		return (6);
	if (opcode == ZJMP)
		return (20);
	if (opcode == LDI || opcode == STI)
		return (25);
	if (opcode == FORK)
		return (800);
	if (opcode == LLDI)
		return (50);
	if (opcode == LFORK)
		return (1000);
	if (opcode == AFF)
		return (2);
	return (0);
}
