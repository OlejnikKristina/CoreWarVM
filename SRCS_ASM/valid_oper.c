/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:44:58 by abumbier          #+#    #+#             */
/*   Updated: 2019/12/10 17:40:19 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	valid_oper(t_parts **oper)
{
	int	line;
	int	arg_c;
	int	oper_code;

	line = (*oper)->line;
	oper_code = (*oper)->token;
	arg_c = 1;
	while ((*oper) && (*oper)->line == line)
	{
		//check for multiple ',' and invalid labels or numbers
		if ((*oper)->token == DIR)
			valid_direct(arg_c, oper_code);
		else if ((*oper)->token == IND)
			valid_indirect(arg_c, oper_code);
		else if ((*oper)->token == REGISTRY)
			valid_registry(arg_c, oper_code);
		(*oper) = (*oper)->next;
		//incrementing here?
	}
}

int	valid_direct(int arg_num, int oper_code)
{
	int	i;
	int	arg1[] = {0x01, 0x02, 0x06, 0x07, 0x08, \
	0x09, 0x0a, 0x0c, 0x0d, 0x0e, 0x0f};
	int	arg2[] = {0x06, 0x07, 0x08, 0x0a, 0x0b, 0x0e};
	int	arg3[] = {0x0b};

	i = 0;
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
	} //10
	if (arg_num == 3)
			if (oper_code == arg3[i])
				return (1);
	return (0);
}
	// if (arg_num == 1)
	// {
	// 	while (i < 11) //arg1 len
	// 	{
	// 		if (oper_code == arg1[i])
	// 			return (1);
	// 		i++;
	// 	}
	// }
	// else if (arg_num == 2)
	// {
	// 	while (i < 6) //arg2 len
	// 	{
	// 		if (oper_code == arg2[i])
	// 			return (1);
	// 		i++;
	// 	}
	// } //17

int	valid_indirect(int arg_num, int oper_code)
{
	//for 1st arg all the possible oper.

	//for 2nd arg all the possible operations

	//for 3rd arg all the possible operations
}

int	valid_registry(int arg_num, int oper_code)
{
	//for 1st arg all the possible oper.

	//for 2nd arg all the possible operations

	//for 3rd arg all the possible operations
}