/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 23:52:32 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/22 12:45:20 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*change_base64(int64_t value, short base, char letters[])
{
	char		num[42];
	unsigned	i;
	unsigned	mod;

	i = 0;
	ft_memset((void *)num, '\0', 42);
	while (i < 42)
	{
		if (value <= 1)
		{
			mod = value % base;
			(0 < mod) ? (num[i] = '1') : 1;
			break ;
		}
		else
		{
			mod = value % base;
			(9 < mod) ? (num[i] = letters[mod - 10]) :
			(num[i] = mod + '0');
		}
		value /= base;
		i++;
	}
	ft_strrev(num);
	return (ft_strdup(num));
}

char		*itoa_base64(int64_t value, short base, bool uppercase)
{
	char		letters[27];

	if (value == 0)
		return (ft_strdup("0"));
	if (base == 10)
		return (itoa64(value));
	if (base < 2 || base > 26)
		return (NULL);
	(uppercase) ? ft_strcpy(letters, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") :
	ft_strcpy(letters, "abcdefghijklmnopqrstuvwxyz");
	return (change_base64(value, base, letters));
}

static char	*change_base64u(uint64_t value, short base, char letters[])
{
	char		num[42];
	unsigned	i;
	unsigned	mod;

	i = 0;
	ft_memset((void *)num, '\0', 42);
	while (i < 42)
	{
		if (value <= 1)
		{
			mod = value % base;
			(0 < mod) ? (num[i] = '1') : 1;
			break ;
		}
		else
		{
			mod = value % base;
			(9 < mod) ? (num[i] = letters[mod - 10]) :
			(num[i] = mod + '0');
		}
		value /= base;
		i++;
	}
	ft_strrev(num);
	return (ft_strdup(num));
}

char		*itoa_base64u(uint64_t value, short base, bool uppercase)
{
	char		letters[27];

	if (value == 0)
		return (ft_strdup("0"));
	if (base == 10)
		return (itoa64u(value));
	if (base < 2 || base > 26)
		return (NULL);
	(uppercase) ? ft_strcpy(letters, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") :
	ft_strcpy(letters, "abcdefghijklmnopqrstuvwxyz");
	return (change_base64u(value, base, letters));
}
