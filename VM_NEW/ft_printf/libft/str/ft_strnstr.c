/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 20:21:31 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/12 18:06:54 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	unsigned int i;
	unsigned int y;
	unsigned int x;

	i = 0;
	y = 0;
	if (needle[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		x = i;
		if (str[i] == needle[y])
		{
			while (
				str[x] == needle[y] && str[x] && needle[y] && x++ < len)
				y++;
			if (needle[y] == '\0')
				return ((char *)&str[x - y]);
			else
				y = 0;
		}
		i++;
	}
	return (NULL);
}
