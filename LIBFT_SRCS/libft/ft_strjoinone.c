/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoinone.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/28 17:10:43 by asulliva       #+#    #+#                */
/*   Updated: 2019/07/10 14:05:12 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoinone(char *s, char c)
{
	int		i;
	int		j;
	char	*str;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	j = 0;
	str = ft_strnew(i + 1);
	if (!str)
		return (NULL);
	while (j < i)
	{
		str[j] = s[j];
		j++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}
