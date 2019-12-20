/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cor_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:01:19 by abumbier          #+#    #+#             */
/*   Updated: 2019/12/19 16:53:03 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

//before writing anything swap the coresponding bits

/*
*/


void		write_magic_header(int wfd)
{
	int	magic;

	// get_magic_header form the .h file
	// magic = -360451328;
	magic = swap_4_bytes(COREWAR_EXEC_MAGIC);
	write(wfd, &magic, 4);
}

void		write_str(char *name, int limit, int wfd)
{
	int		i;
	char	c;

	i = 0;
	while (name[i])
	{
		c = name[i];
		write(wfd, &c, 1);
		i++;
	}
	i = limit - i;
	if (i > 0)
		write_null_bytes(i, wfd);
}

void		write_cor_file(t_asm *data)
{
	write_magic_header(data->wfd);
	write_str(data->name, PROG_NAME_LENGTH, data->wfd);
	write_null_bytes(4, data->wfd);
	write_size(data->parts, data->wfd);
	write_str(data->comment, COMMENT_LENGTH, data->wfd);
	write_null_bytes(4, data->wfd);
	write_champ_byte(data);
}