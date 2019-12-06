/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 18:18:10 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/06 18:38:00 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	@desc	- function frees up to 3 2D arrays
**	@param	- char **arr1, array to be freed
**			- char **arr2, array to be freed
**			- int flag, 0 if arr2 freed, 1 if arr1 freed, 2 for both 
*/

void	free_arr(char **arr1, char ***arr2, int flag)
{
	int		i;

	if (flag && *arr1)
	{
		free(*arr1);
		*arr1 = NULL;
	}
	if ((!flag || flag == 2) && arr2 && *arr2)
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

/*
**	@desc	- function frees main struct
**	@param	- t_asm *data, main struct
*/

void	free_data(t_asm *data)
{
	// free(data->comment);
	// data->comment = NULL;
	// free(data->name);
	// data->name = NULL;
	free(data);
}
