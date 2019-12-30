/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 14:54:36 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/10 15:41:24 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	@desc 	- prints error message and exits
**	@param	- string message to be printed
*/

void	error(char *message, int line)
{
	if (line)
		ft_printf("Error in line %d: ");
	else
		ft_printf("Error: ");
	ft_putendl(message);
	exit(1);
}
