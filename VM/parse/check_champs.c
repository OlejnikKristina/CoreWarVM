/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_champs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 20:30:58 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/24 15:57:18 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- checks file is valid
**	@param	- char *name, name of the file
**	@return	- 1 on success, 0 on failure
*/

int	check_file(char *name)
{
	int		fd;
	char	c;

	fd = open(name, O_RDONLY);
	if (fd < 3)
	{
		ft_printf("%{RED_B}Can't open file [%s]\n", name);
		ft_printf("%{RESET}");
		return (0);
	}
	else if (read(fd, &c, 0) < 0)
	{
		ft_printf("%{RED_B}Can't read from file [%s]\n", name);
		ft_printf("%{RESET}");
		return (0);
	}
	close(fd);
	return (1);
}

/*
**	@desc	- checks if file name is correct
**	@param	- char *name, file name
**	@return	- 1 on succes, 0 on failure
*/

int	check_name(char *name)
{
	int		len;

	len = ft_strlen(name);
	if (5 <= len && ft_strstr(&name[len - 4], ".cor"))
		return (1);
	return (0);
}
