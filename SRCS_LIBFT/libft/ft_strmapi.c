/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 15:23:57 by asulliva       #+#    #+#                */
/*   Updated: 2019/07/11 17:09:32 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int			i;
	char		*tab;

	i = 0;
	if (!s || !f)
		return (NULL);
	tab = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!tab)
		return (NULL);
	while (s[i])
	{
		tab[i] = f(i, s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
