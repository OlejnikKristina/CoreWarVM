/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_toupper.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 16:09:05 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/01/20 16:12:23 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_toupper(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		i++;
	}
	return (s);
}
