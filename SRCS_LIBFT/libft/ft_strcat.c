/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:30:45 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:30:46 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (s1[i])
		i++;
	while (s2[x])
	{
		s1[i] = s2[x];
		i++;
		x++;
	}
	s1[i] = '\0';
	return (s1);
}
