/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:31:03 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:31:05 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while ((s1[0] == s2[0]) && (s1[0] != '\0' || s2[0] != '\0'))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
