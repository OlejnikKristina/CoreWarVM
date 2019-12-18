/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_champ_byte.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:33:41 by abumbier          #+#    #+#             */
/*   Updated: 2019/12/18 16:27:38 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"


static void	write_line(t_parts *start, t_parts *parts, int wfd)
{
	int	line;

	line = parts;
	parts = parts->next;
	while (parts && line == parts->line)
	{
		if (parts->token == REG)
			write_reg();
		else if (parts->token == IND)
			write_ind();
		else if (parts->token == DIR)
			write_dir();
		parts = parts->next;
	}
	// if step on label iter through label struct and find corresponding line.
	// calculate arg value from that line. (do we take current opp size in account if we move up?)
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
		if (op != 0x01 && op != 0x09 && op != 0x0c && op != 0x0f)
		{
			enc = encoding_byte(parts->token);
			write(data->wfd, &enc, 1);
		}
		write_line(data->parts, parts, data->wfd);
	}
}