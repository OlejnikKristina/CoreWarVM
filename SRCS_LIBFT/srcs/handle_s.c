/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_s.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 19:00:05 by tmeulenb       #+#    #+#                */
/*   Updated: 2019/04/08 15:57:12 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_s_minus(t_print *ptr, char *s)
{
	int		i;
	int		len;

	i = 0;
	len = get_len_s(ptr, s);
	ptr->g_count += len;
	if (ptr->pc && ptr->pc < (int)ft_strlen(s))
	{
		if (!(s[0] == 0))
		{
			while (i < ptr->pc)
			{
				ft_putchar(s[i]);
				i++;
			}
		}
	}
	else
	{
		if (!(s[0] == 0))
			ft_putstr(s);
	}
	if (ptr->w)
		space_s(ptr, (len - len_s(ptr, s)));
}

void	put_s(t_print *ptr, char *s, int i)
{
	int		len;

	len = get_len_s(ptr, s);
	ptr->g_count += len;
	if (ptr->w)
		space_s(ptr, (len - len_s(ptr, s)));
	if (!ptr->minus)
	{
		if (ptr->pc && ptr->pc < (int)ft_strlen(s))
		{
			if (!(s[0] == 0))
			{
				while (i < ptr->pc)
				{
					ft_putchar(s[i]);
					i++;
				}
			}
		}
		else
		{
			if (!(s[0] == 0))
				ft_putstr(s);
		}
	}
}

void	put_null_s_minus(t_print *ptr, char *nullstring)
{
	int		i;
	int		len;

	i = 0;
	len = get_len_s(ptr, nullstring);
	ptr->g_count += len;
	if (ptr->pc < 6 && ptr->pc)
		while (i < ptr->pc)
		{
			ft_putchar(nullstring[i]);
			i++;
		}
	else
		ft_putstr(nullstring);
	if (ptr->w)
		space_s(ptr, (len - len_s(ptr, nullstring)));
	if (nullstring)
		free(nullstring);
}

void	put_null_s(t_print *ptr)
{
	char	*nullstring;
	int		i;
	int		len;

	nullstring = ft_strdup("(null)");
	if (ptr->minus)
		put_null_s_minus(ptr, nullstring);
	else
	{
		i = 0;
		len = get_len_s(ptr, nullstring);
		ptr->g_count += len;
		if (ptr->w)
			space_s(ptr, (len - len_s(ptr, nullstring)));
		if (ptr->pc < 6 && ptr->pc)
			while (i < ptr->pc)
			{
				ft_putchar(nullstring[i]);
				i++;
			}
		else
			ft_putstr(nullstring);
	}
	if (!ptr->minus)
		free(nullstring);
}

void	handle_s(va_list ap, t_print *ptr)
{
	char	*str;

	str = va_arg(ap, char*);
	if ((ptr->pc == -1 || (ptr->dot && ptr->pc == 0)) && !ptr->w)
		return ;
	if (!str)
		put_null_s(ptr);
	else if (!ptr->minus)
		put_s(ptr, str, 0);
	else if (ptr->minus)
		put_s_minus(ptr, str);
	return ;
}
