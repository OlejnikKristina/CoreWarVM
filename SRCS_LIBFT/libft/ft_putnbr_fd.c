/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:30:26 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:30:27 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putnbr_fd(int c, int fd)
{
	if (c == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
		return ;
	}
	if (c < 0)
	{
		ft_putchar_fd('-', fd);
		c = c * -1;
	}
	if (c > 9)
	{
		ft_putnbr_fd(c / 10, fd);
		ft_putchar_fd((c % 10) + 48, fd);
	}
	else
		ft_putchar_fd(c + 48, fd);
}
