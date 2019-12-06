/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 14:17:50 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/06 14:55:56 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_asm	*init(int ac, char **av, char **s)
{
	t_asm	*data;

	data = (t_asm*)ft_memalloc(sizeof(t_asm));
	data->rfd = open(av[ac - 1], O_RDONLY);
	if (data->rfd < 3 || read(data->rfd, &s, 0) < 0)
		return (NULL);
	return (data);
}

int		main(int ac, char **av)
{
	t_asm	*data;
	char	*s;

	if (ac < 2)
		error("usage ./asm <file_name>");
	data = init(ac, av, &s);
	if (!data)
		error("Invalid file");
	parse(data, &s);
	return (0);
}
