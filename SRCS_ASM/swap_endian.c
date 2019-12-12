/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_endian.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 21:15:27 by abumbier          #+#    #+#             */
/*   Updated: 2019/12/12 21:38:40 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	@descr	- functions swap (4 or 2)bytes between little and big endian.
*/

int		swap_4_bytes(int num)
{
	int	swap;

	swap = ((num >> 24) & 0xff) | ((num << 8) & 0xff0000) |
			((num >> 8) & 0xff00) | ((num << 24) & 0xff000000);
}

short	swap_2_bytes(short num)
{
	short swap;

	swap = (num >> 8) | (num << 8);
}
