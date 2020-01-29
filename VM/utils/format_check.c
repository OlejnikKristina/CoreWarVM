/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_check.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/17 16:02:49 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/23 17:30:29 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

static int	whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
			c == '\r' || c == '\v' || c == '\f');
}

static int	valid_str(char *s, char *format, int *i)
{
	char	*start;

	start = s;
	if (whitespace(*s))
		return (0);
	while (*s != *format)
	{
		if (!*s || whitespace(*s))
			return (0);
		++s;
	}
	*i = s - start;
	return (1);
}

static int	valid_numb(char *s, char c, int *i)
{
	char	*start;

	start = s;
	if (!ft_isdigit(*s) && *s != '-')
		return (0);
	while (*s != c)
	{
		if (!*s || !ft_isdigit(*s))
			return (0);
		++s;
	}
	*i = s - start;
	return (1);
}

static int	valid_format(char *format, char *s, int *i)
{
	++format;
	if (*format == 'd')
		if (!valid_numb(s, *(format + 1), i))
			return (0);
	if (*format == 's')
		if (!valid_str(s, format + 1, i))
			return (0);
	return (1);
}

int			format_check(char *format, char *s)
{
	int		i;

	if (!format || !s)
		return (0);
	while (*format && *s)
	{
		if (*format == '%')
		{
			if (!valid_format(format, s, &i))
				return (0);
			format += 2;
			s += i;
		}
		else
		{
			if (*format != *s)
				return (0);
			++format;
			++s;
		}
	}
	if (*format || *s)
		return (0);
	return (1);
}
