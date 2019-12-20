/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_champ_byte.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 18:33:41 by abumbier       #+#    #+#                */
/*   Updated: 2019/12/20 16:15:32 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"


static void	write_reg(int value, int wfd)
{
	char reg;

	reg = (char)value;
	write(wfd, &reg, 1);
}

void		write_ind(int value, int wfd)
{
	short ind;
	short swap;

	ind = (short)value;
	swap = swap_2_bytes(ind);
	write(wfd, &swap, 2);
}

static void	write_line(t_asm *data, t_parts *parts)
{
	int	op;
	int	line;

	op = parts->token;
	line = parts->line;
	parts = parts->next;
	while (parts && line == parts->line)
	{
		if (parts->token == REG)
			write_reg(parts->value, data->wfd);
		else if (parts->token == IND)
			write_ind(parts->value, data->wfd);
		else if (parts->token == DIR)
			write_dir(data, parts, op);
		parts = parts->next;
	}
}

/*
**	Assumes that the *parts list starts with an operation and the syntax is correct
*/

void		write_champ_byte(t_asm *data)
{
	char	op;
	char	enc;
	t_parts	*parts;

	parts = data->parts;
	while (parts)
	{
		op = parts->token;	// check if its actually an oper token?
		write(data->wfd, &op, 1);
		ft_printf("%#X\n", op);
		if (op != 0x01 && op != 0x09 && op != 0x0c && op != 0x0f)
		{
			enc = encoding_byte(parts);
			ft_printf("%#X\n", enc);
			write(data->wfd, &enc, 1);
		}
		write_line(data, parts);
	}
}