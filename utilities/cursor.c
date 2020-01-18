/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cursor.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/27 16:50:58 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/06 15:15:42 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

void	print_reg(uint8_t *reg)
{
	uint8_t	i;

	i = 0;
	while (i < REG_NUMBER)
	{
		ft_printf("r%d = %d\n", i + 1, reg[i]);
		i++;
	}
}

uint8_t	*init_reg(uint8_t player_id)
{
	uint8_t	*reg;

	reg = ft_memalloc(sizeof(uint8_t) * REG_NUMBER);
	reg[0] = player_id;
	return (reg);
}

void	test_reg(void)
{
	uint8_t	*reg;

	reg = init_reg(1);
	print_reg(reg);
}
