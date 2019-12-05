/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:30:14 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:30:15 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putendl_fd(char const *c, int fd)
{
	int i;

	i = 0;
	if (!c)
		return ;
	while (c[i])
	{
		ft_putchar_fd(c[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}
