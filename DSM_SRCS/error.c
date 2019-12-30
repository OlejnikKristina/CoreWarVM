/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 14:54:36 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/30 20:11:59 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/dsm.h"

/*
**	@desc 	- prints error message and exits
**	@param	- string message to be printed
**			- int usage, print usage or not
*/

void	error(char *message, int usage)
{
	ft_printf("Error: ");
	ft_putendl(message);
	if (usage)
		ft_printf("Usage: ./dsm [file name]");
	exit(1);
}
