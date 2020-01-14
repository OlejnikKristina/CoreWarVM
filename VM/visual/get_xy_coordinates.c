/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_xy_coordinates.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 19:52:46 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/14 19:52:55 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_visual.h"

void	get_xy_coordinates(int *x, int *y, int address)
{
	*y = address / 64 + OFFSETY + 1;
	*x = (address % 64) * 3 + OFFSETX;
}
