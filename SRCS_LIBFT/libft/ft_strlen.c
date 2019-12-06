/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:32:04 by awehlbur       #+#    #+#                */
/*   Updated: 2019/12/06 16:40:08 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t		ft_strlen(const char *s)
{
	int		count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}
