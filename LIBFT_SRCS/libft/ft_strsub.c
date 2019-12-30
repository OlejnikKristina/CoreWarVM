/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 16:23:46 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/28 16:40:04 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strsub(const char *s, unsigned int start, size_t len)
{
	unsigned int		stop;
	char				*str;
	int					i;

	stop = start + len;
	i = 0;
	if (!s)
		return (NULL);
	str = (char*)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (start < stop)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
