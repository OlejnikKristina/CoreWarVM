/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 20:21:31 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/08 16:17:49 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str_mapi;

	if (!s || !f)
		return (NULL);
	str_mapi = ft_strnew(ft_strlen(s));
	if (!str_mapi)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str_mapi[i] = f(i, s[i]);
		i++;
	}
	str_mapi[i] = '\0';
	return (str_mapi);
}
