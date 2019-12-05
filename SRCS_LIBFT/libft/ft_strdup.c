/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 14:33:21 by asulliva       #+#    #+#                */
/*   Updated: 2019/10/19 16:08:00 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		length;
	int		i;
	char	*str;

	length = 0;
	while (src[length])
		length++;
	str = (char*)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < length)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
