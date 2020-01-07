/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:32:33 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:32:34 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		x;

	i = 0;
	x = 0;
	while (s1[i])
		i++;
	while (x < n && s2[x])
	{
		s1[i] = s2[x];
		i++;
		x++;
	}
	s1[i] = '\0';
	return (s1);
}
