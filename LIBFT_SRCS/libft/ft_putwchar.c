/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putwchar.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 19:03:48 by tmeulenb       #+#    #+#                */
/*   Updated: 2019/04/07 12:11:00 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_putwchar2(unsigned int c, char *letter)
{
	if (0x800 <= c && c <= 0xFFF)
	{
		letter[0] = ((c & 0x3F000) >> 12) | 0xE0;
		letter[1] = ((c & 0xFC0) >> 6) | 0x80;
		letter[2] = (c & 0x3F) | 0x80;
		return (write(1, letter, 3));
	}
	if (0x10000 <= c && c <= 0x10FFF)
	{
		letter[0] = ((c & 0x1C0000) >> 18) | 0xF0;
		letter[1] = ((c & 0x3F000) >> 12) | 0x80;
		letter[2] = ((c & 0xFC0) >> 6) | 0x80;
		letter[3] = (c & 0x3F) | 0x80;
		return (write(1, letter, 4));
	}
	return (0);
}

unsigned long	ft_putwchar(unsigned int c)
{
	char	letter[4];

	if (0 < c && c <= 0x7F)
		return (write(1, &c, 1));
	if (0x80 <= c && c <= 0x7FF)
	{
		letter[0] = ((c & 0xFC0) >> 6) | 0xC0;
		letter[1] = (c & 0x3F) | 0x80;
		return (write(1, letter, 2));
	}
	if (0x800 <= c && c <= 0xFFF)
		return (ft_putwchar2(c, letter));
	if (0x10000 <= c && c <= 0x10FFF)
		return (ft_putwchar2(c, letter));
	return (0);
}
