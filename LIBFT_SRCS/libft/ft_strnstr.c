/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:33:02 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:33:03 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int		i;
	char	*str;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack != '\0' && n > 0)
	{
		i = 0;
		str = (char*)haystack;
		while ((needle[i] == haystack[i]) \
	&& (needle[i] != '\0') && ((i - n) > 0))
			i++;
		if (needle[i] == '\0')
			return (str);
		haystack++;
		n--;
	}
	return (NULL);
}
