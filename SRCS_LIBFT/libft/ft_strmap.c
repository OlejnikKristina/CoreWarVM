/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 15:15:52 by asulliva       #+#    #+#                */
/*   Updated: 2019/07/11 17:09:15 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strmap(const char *s, char (*f)(char))
{
	int			i;
	char		*tab;

	i = 0;
	if (!s || !f)
		return (NULL);
	tab = (char*)malloc(sizeof(char) * ft_strlen((char*)s) + 1);
	if (!tab)
		return (NULL);
	while (s[i])
	{
		tab[i] = f(s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
