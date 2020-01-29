/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 11:26:19 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/01 16:02:12 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int len;

	len = ft_strlen(str);
	if (c == '\0')
		return ((char *)&str[len]);
	while (0 <= len)
	{
		if (str[len] == c)
			return ((char *)&str[len]);
		len--;
	}
	return (NULL);
}
