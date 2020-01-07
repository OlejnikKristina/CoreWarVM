/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_int_array.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 15:58:55 by asulliva       #+#    #+#                */
/*   Updated: 2019/07/09 15:58:57 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int_array(int *array, int arr_size)
{
	int i;

	i = 0;
	if (arr_size > 0)
		ft_putchar('[');
	while (i < arr_size)
	{
		if (i + 1 == arr_size)
		{
			ft_putnbr(array[i]);
			ft_putstr("]\n");
		}
		else
		{
			ft_putnbr(array[i]);
			ft_putstr(", ");
		}
		i++;
	}
}
