/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 15:25:38 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/05 17:00:06 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

/*
**	@desc	- function get a registry value
**	@param	- int line, line number for error
**			- char *s, the registry + number
**	@return	- int ret, the value
*/

static int	handle_reg(int line, char *s)
{
	int	ret;

	ret = (int)ft_atoi(&s[1]);
	if (ret < 1 || ret > 99)
		error("Registry out of bounds", line);
	return (ret);
}

/*
**	@desc	- function get a direct value
**	@param	- char *s, the direct_char + value
**	@return	- int ret, the value
*/

static int	handle_dir(char *s)
{
	int	ret;

	if (s[1] == LABEL_CHAR)
		return (MAX_INT);
	else if (ft_isdigit(s[1]) || s[1] == '-')
	{
		ret = (int)ft_atoi(&s[1]);
		return (ret);
	}
	return (MAX_INT);
}

/*
**	@desc	- function get a indirect value
**	@param	- char *s, the value in a string
**	@return	- int ret, the value
*/

static int	handle_ind(char *s)
{
	int	ret;

	if (s[0] == LABEL_CHAR)
		return (MAX_INT);
	else if (ft_isdigit(s[0]) || s[0] == '-')
	{
		ret = (int)ft_atoi(s);
		return (ret);
	}
	return (MAX_INT);
}

/*
**	@desc	- function gets the value of the argument token
**	@param	- int token, the token type
**			- int line, number of the line (in case of errors)
**			- char *s, the argument
**	@return	- int ret, the value of the token, -1 if error
*/

int			get_value(int token, int line, char *s)
{
	if (token == REG)
		return (handle_reg(line, s));
	else if (token == DIR)
		return (handle_dir(s));
	else if (token == IND)
		return (handle_ind(s));
	error("Invalid token", line);
	return (MAX_INT);
}

/*
**	@desc	- function decides if string is argument or instruction
**	@param	- char *s, string to be checked
**	@return	- returns correct token for the given string
*/

int			get_token(char *s)
{
	int		ret;

	ret = check_instruction(s);
	if (ret)
		return (ret);
	else
		return (get_argument(s));
}
