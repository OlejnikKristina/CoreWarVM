/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 20:21:31 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/08 16:16:00 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*newstr;
	size_t		len_s1;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	if (!
	(newstr = ft_strnew(len_s1 + ft_strlen(s2))))
		return (NULL);
	newstr = ft_strcpy(newstr, s1);
	newstr = ft_strcpy(newstr + len_s1, s2);
	return (&newstr[-len_s1]);
}
