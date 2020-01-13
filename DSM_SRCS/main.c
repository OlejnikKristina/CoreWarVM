/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 15:31:38 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/05 16:57:30 by asulliva      ########   odam.nl         */
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
	data->file_name = av[ac - 1];
	if (data->rfd < 3 || read(data->rfd, data->comment, 0) < 0)
		return (NULL);
	return (data);
}

/*
**	@desc	- function sets/gives the fd of the read file
**	@param	- int rfd, !0 first time to set, 0 after
**	@return	- static int data_rfd, the fd of the file read
*/

int				get_rfd(int rfd)
{
	static int	data_rfd = 0;

	if (!data_rfd)
		data_rfd = rfd;
	return (data_rfd);
}

int				main(int ac, char **av)
{
	t_dsm	*data;

	if (ac != 2)
		error("Invalid amount of arguments", 1);
	check_file(av[ac - 1]);
	data = init(ac, av);
	get_rfd(data->rfd);
	if (!data)
		error("Unable to read file", 0);
	parse(data);
	close(data->rfd);
	write_file(data);
	free_all(data);
	return (0);
}
