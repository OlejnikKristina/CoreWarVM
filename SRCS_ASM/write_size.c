/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:41:45 by abumbier          #+#    #+#             */
/*   Updated: 2019/12/17 19:38:48 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	arg_sizes(t_parts **parts, int op, int *size)
{
	int	line;
	int	arg_size;

	arg_size = 0;
	line = (*parts)->line;
	*parts = (*parts)->next;
	while (*parts && line == (*parts)->line)
	{
		if ((*parts)->token == REG)
			arg_size++;
		else if ((*parts)->token == IND)
			arg_size += 2;
		else if ((*parts)->token == DIR)
		{
			if ((op >= 0x01 && op <= 0x08) || op == 0x0D || op == 0x10)
				arg_size += 4;
			else
				arg_size += 2;
		}
		*parts = (*parts)->next;
	}
	(*size) += arg_size;
	return (arg_size);
}

static int	line_sizes(t_parts *parts)
{
	int		op;
	int		size; //num of bytes
	t_parts	*curr_oper;

	while (parts)
	{
		curr_oper = parts;
		op = curr_oper->token;
		curr_oper->line_size++; // oper_code == 1 byte
		if (op != 0x01 && op != 0x09 && op != 0x0c && op != 0x0f)
			curr_oper->line_size++;
		curr_oper->line_size += arg_sizes(&parts, op, &size);
	}
	return (size);
}

void		write_size(t_parts *parts, int wfd)
{
	int	size;
	int	write_size;

	size = line_sizes(parts);
	write_size = swap_4_bytes(size);
	write(wfd, &write_size, 4);
}