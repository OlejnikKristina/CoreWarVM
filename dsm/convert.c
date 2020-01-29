/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 16:35:54 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/21 16:35:35 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/dsm.h"

/*
**	@desc	- function converts binary to decimal
**	@param	- unsigned char *s, the read binary
**			- int size, amount of bytes
**	@return	- int, returns the converted number
*/

int	convert(unsigned char *s, int size)
{
	int				i;
	unsigned int	temp;

	i = 0;
	temp = 0;
	while (i < size)
	{
		temp = temp << 8;
		temp |= s[i];
		i++;
	}
	if (size == 1)
		return ((char)temp);
	else if (size == 2)
		return ((short)temp);
	return ((int)temp);
}
