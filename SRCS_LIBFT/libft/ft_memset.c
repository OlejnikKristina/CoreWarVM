/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:29:51 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:29:52 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*sn;
	int				i;

	i = 0;
	if (n == 0)
		return (s);
	sn = (unsigned char *)s;
	while (n)
	{
		sn[i] = c;
		i++;
		n--;
	}
	return (sn);
}
