/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:29:10 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:29:11 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;

	d = dst;
	i = 0;
	while (i < n)
	{
		if (((unsigned char*)src)[i] == (unsigned char)c)
		{
			d[i] = ((unsigned char*)src)[i];
			i++;
			return (&dst[i]);
		}
		d[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (NULL);
}
