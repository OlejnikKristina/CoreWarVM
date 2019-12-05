/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 14:19:11 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/05 14:20:12 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error(char *message)
{
	ft_putstr("Error: ");
	ft_putendl(message);
	exit(1);
}