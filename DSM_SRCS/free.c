/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 16:38:56 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/05 16:57:32 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/dsm.h"

/*
**	@desc	- function frees the exec code (t_op struct)
**	@param	- t_op *ops, the LL of operations
*/

static void	free_ops(t_op *ops)
{
	t_op	*temp;

	while (ops)
	{
		temp = ops->next;
		free_arr(&(ops->op_name), &(ops->args), 2);
		free(ops);
		ops = temp;
	}
	free(ops);
	free(temp);
}

/*
**	@desc	- main free function
**	@param	- t_dsm *data, struct to be freed
*/

void		free_all(t_dsm *data)
{
	free_ops(data->ops);
	free(data->comment);
	free(data->name);
	free(data);
}
