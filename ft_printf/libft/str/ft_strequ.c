/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strequ.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 20:21:31 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/08 16:25:41 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	unsigned int max_len;

	if (!s1 || !s2)
		return (0);
	if (ft_strlen(s1) <= ft_strlen(s2))
		max_len = ft_strlen(s2);
	else
		max_len = ft_strlen(s1);
	return (ft_strnequ(s1, s2, max_len));
}
