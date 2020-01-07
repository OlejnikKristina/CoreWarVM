/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 20:20:14 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/05 16:57:23 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/dsm.h"

/*
**	@desc 	- prints error message and exits
**	@param	- string message to be printed
**			- int usage, print usage or not
*/

void	error(char *message, int usage)
{
	ft_printf("Error: ");
	ft_putendl(message);
	if (usage)
		ft_printf("Usage: ./dsm [file name]");
	exit(1);
}

/*
**	@desc	- function that tells you if operation has encoding byte
**	@param	- int op, the given operation code
**	@return	- 1 if operation encoding byte, 0 if not
*/

int		enc_byte(int op)
{
	if (op == LIVE || op == ZJMP || op == FORK || op == LFORK)
		return (0);
	return (1);
}

/*
**	@desc	- function that tells you what size the dir is for given op
**	@param	- int op, the given operation code
**	@return	- size of the T_DIR (2 or 4)
*/

int		dir_size(int op)
{
	if (op == ZJMP || op == LDI || op == STI ||
	op == FORK || op == LLDI || op == LFORK)
		return (2);
	return (4);
}

/*
**	@desc	- function that tells you how many args for given op
**	@param	- int op, the given operation code
**	@return	- number of argument (1, 2 or 3)
*/

int		arg_amnt(int op)
{
	if (op == LIVE || op == ZJMP || op == FORK ||
	op == LFORK || op == AFF)
		return (1);
	else if (op == LD || op == ST || op == LLD)
		return (2);
	return (3);
}

/*
**	@desc	- function frees up to 3 2D arrays
**	@param	- char **arr1, array to be freed
**			- char **arr2, array to be freed
**			- int flag, 0 if arr1 freed, 1 if arr2 freed, 2 for both
*/

void	free_arr(char **arr1, char ***arr2, int flag)
{
	int		i;

	if ((!flag || flag == 2) && *arr1)
	{
		free(*arr1);
		*arr1 = NULL;
	}
	if (flag && arr2 && *arr2)
	{
		i = 0;
		while (arr2[0][i])
		{
			free(arr2[0][i]);
			arr2[0][i] = 0;
			i++;
		}
		free(*arr2);
		*arr2 = 0;
	}
}
