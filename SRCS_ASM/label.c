/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   label.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 14:31:21 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/10 15:22:34 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_instruction(char *s)
{
	if (ft_strchr(s, LABEL_CHAR))
		return (0x00);
	if (ft_strcmp(s, "live"))
		return (0x01);
	else if (ft_strcmp(s, "ld"))
		return (0x02);
	else if (ft_strcmp(s, "st"))
		return (0x03);
	else if (ft_strcmp(s, "add"))
		return (0x04);
	else if (ft_strcmp(s, "sub"))
		return (0x05);
	else if (ft_strcmp(s, "and"))
		return (0x06);
	else if (ft_strcmp(s, "or"))
		return (0x07);
	else if (ft_strcmp(s, "xor"))
		return (0x08);
	else if (ft_strcmp(s, "zjmp"))
		return (0x09);
	else if (ft_strcmp(s, "ldi"))
		return (0x0a);
	else if (ft_strcmp(s, "sti"))
		return (0x0b);
	else if (ft_strcmp(s, "fork"))
		return (0x0c);
	else if (ft_strcmp(s, "lld"))
		return (0x0d);
	else if (ft_strcmp(s, "lldi"))
		return (0x0e);
	else if (ft_strcmp(s, "lfork"))
		return (0x0f);
	else if (ft_strcmp(s, "aff"))
		return (0x10);
	return (0x00);
}

void	parse_label(t_asm *data, char *s)
{
	char	**split;
	
	data->wfd = 0;
	split = NULL;
	split = ft_strsplit_ws(s);
	// if (check_instruction(split[0]))
		// ft_printf("[%s]\n", split[0]);
}