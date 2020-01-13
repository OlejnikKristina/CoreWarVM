/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_oper_line.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 15:44:58 by abumbier       #+#    #+#                */
/*   Updated: 2020/01/13 15:32:40 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

/*
**	@desc	- function checks if the direct arg is valid for the operation
**	@param	- int arg_num, postion of the argument in the call
**			- int oper_code, the hex code of the operation
**	@return	- DIR, direct code
*/

static int	valid_direct(int arg_num, int oper_code)
{
	int	i;

	i = 0;
	if (arg_num == 3)
		if (oper_code == DIR_ARG3[i])
			return (1);
	while (i < 11)
	{
		if (arg_num == 1)
			if (oper_code == DIR_ARG1[i])
				return (1);
		if (arg_num == 2)
			if (i < 6)
				if (oper_code == DIR_ARG2[i])
					return (1);
		i++;
	}
	return (DIR);
}

/*
**	@desc	- function checks if the indirect arg if valid for the operation
**	@param	- int arg_num, postion of the argument in the call
**			- int oper_code, the hex code of the operation
**	@return	- IND, indirect code
*/

static int	valid_indirect(int arg_num, int oper_code)
{
	int	i;

	i = 0;
	if (arg_num == 3)
		return (0);
	while (i < 7)
	{
		if (arg_num == 1)
			if (oper_code == IND_ARG1[i])
				return (1);
		if (arg_num == 2)
			if (i < 5)
				if (oper_code == IND_ARG2[i])
					return (1);
		i++;
	}
	return (IND);
}

/*
**	@desc	- function checks if the registry arg is valid for the operation
**	@param	- int arg_num, postion of the argument in the call
**			- int oper_code, the hex code of the operation
**	@return	- REG, registry code
*/

static int	valid_registry(int arg_num, int oper_code)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (arg_num == 2)
			if (oper_code == REG_ARG2[i])
				return (1);
		if (arg_num == 1)
			if (i < 10)
				if (oper_code == REG_ARG1[i])
					return (1);
		if (arg_num == 3)
			if (i < 8)
				if (oper_code == REG_ARG3[i])
					return (1);
		i++;
	}
	return (REG);
}

/*
**	@desc	- function returns a detailed error message
**	@param	- int line, line where the error occurs
**			- int arg_c, which argument (1, 2 or 3)
**			- int oper_code, code of the operation
**			- int valid, which type of argument is wrong
**	@return	- int 0, to indicate error
*/

static int	arg_error(int line, int arg_c, int oper_code, int valid)
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
	return (0);
}

/*
**	@desc	- main function to check operation line arguments
**	@param	- t_parts **oper, pointer to the tokenized operation read
**	@return	- int, 1 on succes, 0 on error
*/

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
	while ((*oper) && (*oper)->line == line)
	{
		if ((*oper)->token == DIR)
			valid = valid_direct(arg_c, oper_code);
		else if ((*oper)->token == IND)
			valid = valid_indirect(arg_c, oper_code);
		else if ((*oper)->token == REG)
			valid = valid_registry(arg_c, oper_code);
		if (valid != 1)
			return (arg_error(line, arg_c, oper_code, valid));
		(*oper) = (*oper)->next;
		arg_c++;
	}
	return (1);
}
