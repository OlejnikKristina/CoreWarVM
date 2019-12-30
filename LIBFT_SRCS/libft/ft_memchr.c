/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:29:18 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:29:20 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	size_t			i;

	i = 0;
	src = (void*)s;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
			return ((void*)s + i);
		i++;
	}
	return (NULL);
}
