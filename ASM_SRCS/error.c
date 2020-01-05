/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 14:54:36 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/05 16:59:21 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

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
