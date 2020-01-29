/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:31:40 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/26 18:32:10 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function prints the usage of the program
*/

static void	usage(void)
{
	int		fd;
	char	*line;

	fd = open("./utils/usage_msg.txt", O_RDONLY);
	line = NULL;
	while (0 < get_next_line(fd, &line))
	{
		ft_printf("%s\n", line);
		if (line)
			ft_strdel(&line);
	}
	close(fd);
}

/*
**	@desc	- displays error message and exits
**	@param	- char *message, message to be displayed
*/

void		error(char *message, char *file)
{
	if (!ft_strcmp(message, "usage"))
		usage();
	else
	{
		ft_putstr("Error: ");
		if (file)
			ft_printf("%s[%s]\n", message, file);
		else
			ft_putendl(message);
	}
	exit(0);
}
