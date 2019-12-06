/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_s1.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/07 19:53:52 by tmeulenb       #+#    #+#                */
/*   Updated: 2019/04/08 15:55:49 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	space_s(t_print *ptr, int amount)
{
	int		i;

	i = 0;
	while (i < amount)
	{
		if (!ptr->zero)
			ft_putchar(' ');
		if (ptr->zero)
			ft_putchar('0');
		i++;
	}
}

int		len_s(t_print *ptr, char *s)
{
	int		slen;

	if (s[0] == 0)
		slen = '\0';
	else if (ptr->pc < (int)ft_strlen(s) && ptr->pc && ptr->pc != -1)
		slen = ptr->pc;
	else if (ptr->pc == -1)
		return (0);
	else
		slen = (int)ft_strlen(s);
	return (slen);
}

int		get_len_s(t_print *ptr, char *s)
{
	if (ptr->pc < ptr->w && ptr->w >= (int)ft_strlen(s))
		return (ptr->w);
	else if ((int)ft_strlen(s) > ptr->w && !ptr->pc)
		return (ft_strlen(s));
	else if (!ptr->w && ptr->pc > (int)ft_strlen(s))
		return (ft_strlen(s));
	else if (ptr->w < (int)ft_strlen(s) && ptr->pc > (int)ft_strlen(s))
		return (ft_strlen(s));
	else if (ptr->pc < (int)ft_strlen(s) && ptr->w < ptr->pc)
		return (ptr->pc);
	else if (ptr->w < (int)ft_strlen(s) && ptr->pc >= (int)ft_strlen(s))
		return ((int)ft_strlen(s));
	else if (ptr->w && ptr->pc && ptr->w < (int)ft_strlen(s))
		return (ptr->w);
	else if (ptr->w && ptr->pc && ptr->pc > (int)ft_strlen(s)
	&& ptr->w > (int)ft_strlen(s))
		return (ptr->w);
	else if (!ptr->w && ptr->pc && (!(s[0] == 0)))
		return (ptr->pc);
	else if (ptr->pc == -1 && ptr->w)
		return (ptr->w);
	return (0);
}
