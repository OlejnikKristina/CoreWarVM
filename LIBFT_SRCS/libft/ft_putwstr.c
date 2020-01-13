/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putwstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 19:03:48 by tmeulenb       #+#    #+#                */
/*   Updated: 2019/04/07 12:14:33 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_putwstr(int *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i])
	{
		len += ft_putwchar(str[i]);
		i++;
	}
	return (len);
}
