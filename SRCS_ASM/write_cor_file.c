/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cor_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:01:19 by abumbier          #+#    #+#             */
/*   Updated: 2019/12/13 19:02:11 by abumbier         ###   ########.fr       */
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
	magic = -360451328;
	write(wfd, &magic, 4);
}

// 1) find the number you want to write
// 2) convert it to big endian
// 3) write in the file

void		write_name(char *name, int wfd)
{
	wfd = name[2];
}

void		write_cor_file(t_asm *data)
{
	write_magic_header(data->wfd);
	write_name(data->name, data->wfd);
}