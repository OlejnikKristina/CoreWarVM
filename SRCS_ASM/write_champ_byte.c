/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_champ_byte.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 18:33:41 by abumbier       #+#    #+#                */
/*   Updated: 2019/12/22 21:26:54 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	write_reg(int value, int wfd)
{
	char reg;

	reg = (char)value;
	if (!reg)
		write(wfd, "\0", 1);
	else
		write(wfd, &reg, 1);
	ft_printf("reg %#X\n", reg);
}

void		write_ind(int value, int wfd)
{
	short ind;
	short swap;

	ind = (short)value;
	ft_printf("dec value %d\t\tind %#hX\n", ind, ind);
	if (!ind)
	{
		write_null_bytes(2, wfd);
		return ;
	}
	swap = swap_2_bytes(ind);
	ft_printf("swap %#hX\n", swap);
	write(wfd, &swap, 2);
}

static t_parts	*write_line(t_asm *data, t_parts *parts)
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
	return (parts);
}

/*
**	Assumes that the *parts list starts with an operation and the syntax is correct
*/

void			write_champ_byte(t_asm *data)
{
	char	op;
	char	enc;
	t_parts	*parts;

	parts = data->parts;
	print_parts(parts);
	ft_printf("----------------------------------------------------------------------\n");
	while (parts)
	{
		op = parts->token;	// check if its actually an oper token?
		write(data->wfd, &op, 1);
		ft_printf("%s %#X\n", parts->name, op);
		if (op != 0x01 && op != 0x09 && op != 0x0c && op != 0x0f)
		{
			enc = encoding_byte(parts);
			write(data->wfd, &enc, 1);
			ft_printf("encoding byte %#hhX\n", enc);
		}
		parts = write_line(data, parts);
	}
}