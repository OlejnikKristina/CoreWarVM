/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 15:31:38 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/02 21:38:18 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/dsm.h"

/*
**	@desc	- function checks if the file is a .s file
**	@param	- char *file, name of the file given as argument
*/

static void		check_file(char *file)
{
	int		len;

	len = ft_strlen(file);
	if (ft_strequ(&file[len - 4], ".cor"))
		return ;
	error("File extension must be .cor", 0);
}

/*
**	@desc	- function initalizes main struct
**	@param	- int ac, amount of argument given
**			- char **av, arguments given
**	@return	- t_dsm *data, initiliazed main struct
*/

static t_dsm	*init(int ac, char **av)
{
	t_dsm	*data;

	data = (t_dsm*)ft_memalloc(sizeof(t_dsm));
	data->rfd = open(av[ac - 1], O_RDONLY);
	if (data->rfd < 3 || read(data->rfd, data->comment, 0) < 0)
		return (NULL);
	return (data);
}

int				main(int ac, char **av)
{
	t_dsm	*data;

	if (ac != 2)
		error("Invalid amount of arguments", 1);
	check_file(av[ac - 1]);
	data = init(ac, av);
	if (!data)
		error("Unable to read file", 0);
	parse(data);
	return (0);
}
