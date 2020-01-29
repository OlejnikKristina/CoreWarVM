/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   args.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 21:34:48 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/08 15:26:28 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/dsm.h"

/*
**	@desc	- function returns the type of argument (T_DIR, T_REG, T_IND)
**	@param	- int enc_byte, the encoding byte to read
**			- int nb_arg, which argument we are atm
**	@return	- unsigned char res, type of argument (T_DIR, T_REG, T_IND)
*/

static int	ret_type(int enc_byte, int nb_arg)
{
	unsigned char	mask[3];
	unsigned char	res;

	mask[0] = 0b11000000;
	mask[1] = 0b00110000;
	mask[2] = 0b00001100;
	res = mask[nb_arg] & enc_byte;
	if (nb_arg == 0)
		res /= 64;
	else if (nb_arg == 1)
		res /= 16;
	else
		res /= 4;
	return (res * -1);
}

/*
**	@desc	- function returns the size needed for given argument
**	@param	- int type, type of argument (T_DIR, T_REG, T_IND)
**			- int op, operation code
**	@return	- size of the given argument
*/

static int	get_size(int type, int op)
{
	if (type == REG)
		return (1);
	if (type == IND)
		return (2);
	return (dir_size(op));
}

/*
**	@desc	- function finds the value of the argument
**	@param	- char **args, the arguments as strings (to be filled)
**			- int nb_arg, which argument we are atm
**			- int size, size of the argument to be read
**	@return	- int ret, amount of bytes read
*/

static int	find_value(char **args, int nb_arg, int size)
{
	unsigned char	s[4];
	int				ret;
	int				ret_val;
	char			**combo;

	ret = (int)read(get_rfd(0), s, size);
	if ((int)ft_strlen((char*)s) != size && ret != size)
		error("Invalid argument", 0);
	ret_val = convert(s, size);
	combo = (char**)ft_memalloc(sizeof(char*) * 3);
	combo[0] = args[nb_arg];
	combo[1] = ft_itoa(ret_val);
	args[nb_arg] = ft_strjoin(combo[0], combo[1]);
	free_arr(NULL, &combo, 1);
	return (ret);
}

/*
**	@desc	- function prepares the arguments
**	@param	- int enc_byte, the encoding byte to check
**			- int nb_arg, which argument we are atm
**	@return	- filled string with char corresponding to the arg type
*/

static char	*prep_arg(int enc_byte, int nb_arg)
{
	if (ret_type(enc_byte, nb_arg) == REG)
		return (ft_strdup("r"));
	if (ret_type(enc_byte, nb_arg) == DIR)
		return (ft_strdup("%"));
	if (ret_type(enc_byte, nb_arg) == IND)
		return (ft_strdup(""));
	return (ft_strdup("%"));
}

/*
**	@desc	- function finds out what type of arguments are coming
**			- and fills them in accordingly
**	@param	- t_op *curr, the current op
**			- int enc_byte, the encoding byte, already shifted (enc_byte >> 2)
**			- use enc_byte to find out what argument types are coming up
**			- int arg_amnt, amount of arguments expected for this operation
**			- int op, the operation code
**	@return	- int size, amount of bytes read
*/

int			find_args(t_op *curr, int enc_byte, int arg_amnt, int op)
{
	int		i;
	int		size;
	char	*temp;

	i = 0;
	size = 0;
	curr->args = (char**)ft_memalloc(sizeof(char*) * arg_amnt + 1);
	while (i < arg_amnt)
	{
		curr->args[i] = prep_arg(enc_byte, i);
		size += find_value(curr->args, i, get_size(ret_type(enc_byte, i), op));
		if (i < arg_amnt - 1)
		{
			temp = ft_strjoin(curr->args[i], ",");
			free_arr(&(curr->args[i]), NULL, 0);
			curr->args[i] = temp;
		}
		i++;
	}
	return (size);
}
