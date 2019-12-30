/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_p.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 16:44:46 by tmeulenb       #+#    #+#                */
/*   Updated: 2019/07/10 15:11:29 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(t_print *ptr, unsigned long long n)
{
	int		i;
	int		len;

	i = 0;
	ptr->len = (int)ft_hexlen(n) + 2;
	len = ptr->len;
	if (ptr->pc > (int)ft_hexlen(n))
		len = ptr->pc + 2;
	if (ptr->w > ptr->len && !ptr->minus)
		p_fill_space(ptr, ptr->w - len);
	put_0x(ptr, n);
	i = 0;
	if (ptr->pc > ptr->len)
		p_fill_zero(ptr, len - (ft_hexlen(n) + 2));
	if (!(n == 0 && ptr->pc == -1))
		ptr->g_count += ft_printf("%llx", n);
	if (ptr->w > ptr->len && ptr->minus)
		p_fill_space(ptr, ptr->w - ptr->len);
}

char	*ft_itoa_base(unsigned long long value, int base)
{
	int		i;
	char	*nbr;
	int		neg;

	i = ft_hexlen(value);
	neg = 0;
	nbr = (char*)malloc(sizeof(nbr) * i + 1);
	nbr[i + neg] = '\0';
	while (i > 0)
	{
		i--;
		nbr[i + neg] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}

void	ft_print_h(char *hexstr, t_print *ptr)
{
	ptr->g_count += ft_strlen(hexstr);
	if (ptr->con == 'X')
		ft_putstr(hexstr);
	else
		ft_putstr(ft_str_tolower(hexstr));
	free(hexstr);
	return ;
}

void	ft_put_hex(unsigned long long n, t_print *ptr)
{
	char				*hexstring;

	hexstring = ft_itoa_base(n, 16);
	if (n != 0 && !ptr->zero)
		put_0x(ptr, n);
	if ((ptr->con == 'x' || ptr->con == 'X') && ptr->pc && ptr->hash)
		fill_zero(ptr->pc - ft_hexlen(n), ptr);
	if (!(ptr->dot && ptr->pc == -1 && n == 0))
		ft_print_h(hexstring, ptr);
}

void	handle_p(va_list ap, t_print *ptr)
{
	unsigned long long	n;

	n = va_arg(ap, unsigned long long);
	print_p(ptr, n);
}
