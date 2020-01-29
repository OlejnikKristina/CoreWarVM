/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 20:19:49 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/01 16:02:09 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *fresh_mem;

	fresh_mem = malloc(size);
	if (fresh_mem == NULL)
		return (NULL);
	ft_bzero(fresh_mem, size);
	return (fresh_mem);
}
