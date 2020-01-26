/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 20:21:12 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/05 17:53:14 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		*((unsigned char *)s) = '\0';
		n--;
		s++;
	}
}
