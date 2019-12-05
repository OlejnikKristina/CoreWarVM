/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 16:06:01 by asulliva       #+#    #+#                */
/*   Updated: 2019/07/09 16:06:03 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		while (little[j] == big[i + j] && little[j])
			j++;
		if (j == ft_strlen(little))
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
