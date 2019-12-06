/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 14:17:50 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/06 16:30:23 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	@desc	- initialized the file to be opened
**	@param	- int ac, the number of arguments
**			- char **av, the arguments
**	@return	- t_asm *data, open file and malloced struct
*/

static t_asm	*init(int ac, char **av)
{
	t_asm	*data;

	data = (t_asm*)ft_memalloc(sizeof(t_asm));
	data->rfd = open(av[ac - 1], O_RDONLY);
	if (data->rfd < 3 || read(data->rfd, data->name, 0) < 0)
		return (NULL);
	return (data);
}

/*
**	@desc	- main controller function
**	@param	- int ac, the number of arguments
**			- char **av, the arguments
**	@return	- 0
*/

int				main(int ac, char **av)
{
	t_asm	*data;

	if (ac < 2)
		error("usage ./asm <file_name>");
	data = init(ac, av);
	if (!data)
		error("Invalid file");
	parse(data);
	close(data->rfd);
	return (0);
}
