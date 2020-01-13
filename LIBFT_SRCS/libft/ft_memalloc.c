/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:29:03 by awehlbur       #+#    #+#                */
/*   Updated: 2019/10/17 17:14:34 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void		*ft_memalloc(size_t size)
{
	int		*tab;
	size_t	i;

	i = 0;
	tab = (int*)malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
