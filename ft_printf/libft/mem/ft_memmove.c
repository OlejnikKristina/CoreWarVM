/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 20:19:49 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/12 17:58:35 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p_dest;

	p_dest = (unsigned char	*)dest;
	if (src < dest)
		while (n)
		{
			--n;
			*((unsigned char *)dest + n) = *((unsigned char *)src + n);
		}
	else if (src > dest)
		while (n)
		{
			--n;
			*(unsigned char *)dest = *(unsigned char *)src;
			dest++;
			src++;
		}
	return (p_dest);
}
