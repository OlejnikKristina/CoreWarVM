/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 15:53:19 by krioliin       #+#    #+#                */
/*   Updated: 2019/08/18 22:43:52 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short	ft_putstr_fd(char const *s, int fd)
{
	if (!s || fd < 0)
		return (-1);
	while (*s != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	return (1);
}
