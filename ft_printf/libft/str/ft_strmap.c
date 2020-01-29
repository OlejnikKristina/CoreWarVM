/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 20:21:31 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/08 16:22:44 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*fresh_str;

	if (!s || !f)
		return (NULL);
	fresh_str = ft_strnew(ft_strlen(s));
	if (!fresh_str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		fresh_str[i] = f(s[i]);
		i++;
	}
	fresh_str[i] = '\0';
	return (fresh_str);
}
