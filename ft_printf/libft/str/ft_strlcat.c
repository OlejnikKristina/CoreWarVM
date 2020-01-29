/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 23:24:13 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/12 18:02:52 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_strlcat_end(char **d, char **s, size_t n)
{
	while (**s != '\0')
	{
		if (n != 1)
		{
			**d = **s;
			(*d)++;
			n--;
		}
		(*s)++;
	}
	**d = '\0';
}

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*d;
	char	*s;
	size_t	n;
	size_t	dlen;

	d = dst;
	n = dstsize;
	s = (char *)src;
	while (n && *d)
	{
		d++;
		n--;
	}
	dlen = d - dst;
	n = dstsize - dlen;
	if (n == 0)
		return (dlen + ft_strlen(s));
	ft_strlcat_end(&d, &s, n);
	return (dlen + (s - src));
}
