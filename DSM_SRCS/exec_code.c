/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_code.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 19:39:31 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/30 20:28:37 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/dsm.h"

void	get_line(t_dsm *data, int op, int *size)
{
	if (ENC_BYTE[op])
		{ft_printf("jemoeder\n");size--;}
	else
		ft_printf("jevader\n");
	data->wfd = 0;
}

void	get_exec_code(t_dsm *data)
{
	int	s;
	int	ret;
	int	size;

	ret = 1;
	size = data->size;
	while (ret)
	{
		s = 0;
		ret = read(data->rfd, &s, 1);
		size -= ret;
		if (s < 1 || s > NB_OPS)
			ft_printf("%#X is NOT\n", s);
		else
			get_line(data, s, &size);
	}
	if (size)
		error("Size of champion does not match", 0);
}
