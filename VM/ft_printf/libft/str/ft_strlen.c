/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 20:21:31 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/01 18:09:33 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *s1)
{
	size_t i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	return (i);
}
