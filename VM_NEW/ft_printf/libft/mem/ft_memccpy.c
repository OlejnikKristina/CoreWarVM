/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/24 17:43:12 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/12 17:50:06 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n)
	{
		*(unsigned char *)dest = *(unsigned char *)src;
		if (*(unsigned char *)src == (unsigned char)c)
			return (&dest[1]);
		dest++;
		src++;
		n--;
	}
	return (NULL);
}
