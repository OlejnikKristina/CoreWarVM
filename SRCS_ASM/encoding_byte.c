/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   encoding_byte.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 16:58:59 by abumbier       #+#    #+#                */
/*   Updated: 2019/12/20 16:27:34 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void    print_bits(unsigned char octet)
{
    int z = 128, oct = octet;

    while (z > 0)
    {
        if (oct & z)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        z >>= 1;
    }
	write(1, "\n", 1);
}

static void	add_reg(char *enc, int argc)
{
	char	reg;

	reg = 1;
	*enc = *enc | (reg << argc * 2);

}

static void	add_dir(char *enc, int argc)
{
	char	dir;

	dir = 2;
	*enc = *enc | (dir << argc * 2);
}

static void	add_ind(char *enc, int argc)
{
	char	ind;

	ind = 3;
	*enc = *enc | (ind << argc * 2);
}
/*
**	@desc	- encodes a byte based on the arguments operation has
**	@param	- t_parts *oper, 
*/

char		encoding_byte(t_parts *oper)
{
	int		line;
	char	enc;
	int		i;

	i = 4;
	enc = 0;
	line = oper->line;
	while (oper && line == oper->line)
	{
		if (oper->token == REG)
			add_reg(&enc, i);
		if (oper->token == DIR)
			add_dir(&enc, i);
		if (oper->token == IND)
			add_ind(&enc, i);
		oper = oper->next;
		if (oper->token < LIVE)
			i--;
	}
	return (enc);
}
