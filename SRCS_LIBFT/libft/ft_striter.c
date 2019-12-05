/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:31:41 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:31:42 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s != NULL && *s)
		f(s++);
}
