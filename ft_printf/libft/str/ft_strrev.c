/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 23:52:32 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/24 21:36:28 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char str_rev[])
{
	int			i;
	int			end_str;
	int			len;
	char		temp;

	i = 0;
	end_str = ft_strlen(str_rev);
	len = end_str;
	end_str--;
	while (i < (len / 2))
	{
		temp = str_rev[i];
		str_rev[i] = str_rev[end_str];
		str_rev[end_str] = temp;
		end_str--;
		i++;
	}
	str_rev[len] = '\0';
	return (NULL);
}
