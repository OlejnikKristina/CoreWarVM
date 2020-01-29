/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 20:19:49 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/13 15:11:38 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n)
	{
		if (
			*((unsigned char *)s1++)
			!= *((unsigned char *)s2++))
			break ;
		n--;
	}
	return (*((unsigned char *)s1 - 1) - *((unsigned char *)s2 - 1));
}
