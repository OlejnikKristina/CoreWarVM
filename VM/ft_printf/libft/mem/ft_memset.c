/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 20:19:49 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/12 17:58:01 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*hui;

	i = 0;
	hui = (unsigned char *)s;
	while (i < n)
	{
		hui[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
