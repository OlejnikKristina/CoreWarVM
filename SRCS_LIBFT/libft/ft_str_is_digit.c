/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_is_digit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 14:31:05 by asulliva       #+#    #+#                */
/*   Updated: 2019/10/17 17:15:37 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		str_is_digit(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
