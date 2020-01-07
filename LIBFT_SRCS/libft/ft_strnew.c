/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:32:55 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:32:57 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = ft_memalloc(size + 1);
	return (str);
}
