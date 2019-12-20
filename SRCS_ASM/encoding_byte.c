/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   encoding_byte.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 16:58:59 by abumbier       #+#    #+#                */
/*   Updated: 2019/12/20 16:24:23 by asulliva      ########   odam.nl         */
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
	ft_putendl("");
}

static void	add_reg(char *enc, int argc)
{
	char	reg;

	ft_putendl("reg");
	reg = 1;
	print_bits(*enc);
	*enc = *enc | (reg << argc * 2);
	print_bits(*enc);

}

static void	add_dir(char *enc, int argc)
{
	char	dir;

	ft_putendl("dir");
	dir = 2;
	print_bits(*enc);
	*enc = *enc | (dir << argc * 2);
	print_bits(*enc);
}

static void	add_ind(char *enc, int argc)
{
	char	ind;

	ft_putendl("ind");
	ind = 3;
	print_bits(*enc);
	*enc = *enc | (ind << argc * 2);
	print_bits(*enc);
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
	print_bits(enc);
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
	ft_printf("\nfinal %#X\n\n", enc);
	print_bits(enc);
	ft_printf("\nfinal %d\n\n", enc);
	return (enc);
}
