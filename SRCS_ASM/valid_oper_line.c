/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_oper_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:44:58 by abumbier          #+#    #+#             */
/*   Updated: 2019/12/11 18:15:42 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			valid_direct(int arg_num, int oper_code)
{
	int	i;
	int	arg1[] = {0x01, 0x02, 0x06, 0x07, 0x08, \
	0x09, 0x0a, 0x0c, 0x0d, 0x0e, 0x0f};	//code of oper that can take dir as 1st arg
	int	arg2[] = {0x06, 0x07, 0x08, 0x0a, 0x0b, 0x0e};
	int	arg3[] = {0x0b};

	i = 0;
	if (arg_num == 3)
			if (oper_code == arg3[i])
				return (1);
	while (i < 11)
	{
		if (arg_num == 1)
			if (oper_code == arg1[i])
				return (1);
		if (arg_num == 2)
			if (i < 6)
				if (oper_code == arg2[i])
					return (1);
		i++;
	}
	return (DIR);
}

int			valid_indirect(int arg_num, int oper_code)
{
	int	i;
	int	arg1[] = {0x02, 0x06, 0x07, 0x08, 0x0a, 0x0d, 0x0e};
	int	arg2[] = {0x03, 0x06, 0x07, 0x08, 0x0b};
	
	i = 0;
	if (arg_num == 3)
		return (0);
	while (i < 7)
	{
		if (arg_num == 1)
			if (oper_code == arg1[i])
				return (1);
		if (arg_num == 2)
			if (i < 5)
				if (oper_code == arg2[i])
					return (1);
		i++;
	}
	return (IND);
}

int			valid_registry(int arg_num, int oper_code)
{
	int	i;
	int	arg1[] = {0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x0a, 0x0b, 0x0e, 0x10};
	int	arg2[] = {0x02, 0x03, 0x04, 0x05, 0x06, \
	0x07, 0x08, 0x0a, 0x0b, 0x0d, 0x0e};
	int	arg3[] = {0x04, 0x05, 0x06, 0x07, 0x08, 0x0a, 0x0b, 0x0e};

	i = 0;
	while (i < 11)
	{
		if (arg_num == 2)
			if (oper_code == arg2[i])
				return (1);
		if (arg_num == 1)
			if (i < 10)
				if (oper_code == arg1[i])
					return (1);
		if (arg_num == 3)
			if (i < 8)
				if (oper_code == arg3[i])
					return (1);
		i++;
	}
	return (REG);
}

static void	arg_error(int line, int arg_c, int oper_code, int valid)
{
	char	*dir = "direct";
	char	*ind = "indirect";
	char	*reg = "registry";
	char	*var;

	if (valid == DIR)
		var = dir;
	else if (valid == IND)
		var = ind;
	else
		var = reg;
	ft_printf("Error in line: %d\nOperation with an op_code %#X does not take \
an argument of type -%s- as argument #%d", line, oper_code, var, arg_c);
}

int			valid_oper_line(t_parts **oper)
{
	int	line;
	int	valid;
	int	arg_c;
	int	oper_code;

	line = (*oper)->line;
	oper_code = (*oper)->token;
	arg_c = 1;
	valid = 1;
	(*oper) = (*oper)->next;
	while ((*oper) && (*oper)->line == line)	//while on the same line
	{
		if ((*oper)->token == DIR)
			valid = valid_direct(arg_c, oper_code);
		else if ((*oper)->token == IND)
			valid = valid_indirect(arg_c, oper_code);
		else if ((*oper)->token == REG)
			valid = valid_registry(arg_c, oper_code);
		if (valid != 1)	//checks valid_* return
		{
			arg_error(line, arg_c, oper_code, valid);
			return (0);
		}
		(*oper) = (*oper)->next;
		arg_c++;
	}
	return (1);
}
