/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:44:58 by abumbier          #+#    #+#             */
/*   Updated: 2019/12/10 16:01:00 by abumbier         ###   ########.fr       */
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
		if ((*oper)->token == DIR)
			valid_direct(arg_c, oper_code);
		else if ((*oper)->token == IND)
			valid_indirect(arg_c, oper_code);
		//incrementing here?
	}
}

int	valid_direct(int arg_num, int oper_code)
{
	//for 1st arg all the possible oper.

	//for 2nd arg all the possible operations

	//for 3rd arg all the possible operations
}

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