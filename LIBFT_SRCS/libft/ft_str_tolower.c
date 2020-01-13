/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_tolower.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tmeulenb <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 16:15:16 by tmeulenb      #+#    #+#                 */
/*   Updated: 2019/01/20 16:16:09 by tmeulenb      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_tolower(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		i++;
	}
	return (s);
}
