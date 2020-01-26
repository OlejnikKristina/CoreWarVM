/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_superjoin.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/01 16:10:38 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/19 20:56:23 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_superjoin(char **s1, const char *s2)
{
	char	*holder;

	holder = ft_strjoin(*s1, s2);
	ft_strdel(s1);
	return (holder);
}
