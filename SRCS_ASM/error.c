/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 14:54:36 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/06 16:06:24 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	@desc 	- prints error message and exits
**	@param	- string message to be printed
*/

void	error(char *message)
{
	ft_putstr("Error: ");
	ft_putendl(message);
	exit(1);
}
