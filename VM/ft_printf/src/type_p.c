/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_p.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 14:31:26 by krioliin       #+#    #+#                */
/*   Updated: 2019/06/27 20:45:48 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	p_flag_minus(t_placeholder *result, char sign, int len)
{
	char		*add_space;

	add_space = ft_strnew(len);
	ft_memset((void *)add_space, sign, len);
	result->str = ft_superjoin(&result->str, add_space);
	ft_strdel(&add_space);
}

static	void	p_width(t_format_spec *s, t_placeholder *result)
{
	int			len;
	char		sign;
	char		*add_space;
	char		*holder;

	sign = s->flag_zero ? '0' : ' ';
	len = s->width - s->dig_amount;
	if (len <= 0)
		return ;
	if (!s->flag_minus)
	{
		add_space = ft_strnew(len);
		ft_memset((void *)add_space, sign, len);
		holder = result->str;
		result->str = ft_superjoin(&add_space, result->str);
		ft_strdel(&holder);
		if (s->flag_zero)
		{
			result->str[1] = 'x';
			result->str[len + 1] = '0';
		}
	}
	else if (s->flag_minus)
		p_flag_minus(result, sign, len);
}

static	void	p_precision(t_format_spec *s, t_placeholder *result,
char *address_str)
{
	char	*fill_precis;
	int		prec_size;

	if (s->precision <= s->dig_amount)
		result->str = ft_strdup("0x");
	else
	{
		prec_size = s->precision - s->dig_amount;
		fill_precis = ft_strnew(prec_size + 3);
		ft_memset(fill_precis, '0', prec_size + 2);
		result->str = ft_strdup(fill_precis);
		result->str[1] = 'x';
		ft_strdel(&fill_precis);
	}
	result->str = ft_superjoin(&result->str, address_str);
	s->dig_amount = ft_strlen(result->str);
}

bool			type_p(t_format_spec *specifier, t_placeholder *result,
va_list arg_ptr)
{
	int64_t		address;
	char		*address_str;

	address = va_arg(arg_ptr, long long);
	if (address == 0 && specifier->precision == -42)
	{
		specifier->precision = 0;
		address_str = ft_strnew(0);
	}
	else
		address_str = itoa_base64(address, 16, 0);
	specifier->dig_amount = ft_strlen(address_str);
	p_precision(specifier, result, address_str);
	p_width(specifier, result);
	ft_strdel(&address_str);
	return (true);
}
