/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 15:55:51 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/30 16:20:51 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/dsm.h"

/*
**	@desc	- this function checks the magic header in the file
**	@param	- t_dsm *data, main struct
*/

static void	get_magic_header(t_dsm *data)
{
	unsigned char	s[MAGIC_LENGTH];
	int				i;
	int				magic;
	unsigned int	temp;

	magic = read(data->rfd, (void*)s, 4);
	if (magic < MAGIC_LENGTH)
		error("Invalid magic header", 0);
	i = 0;
	while (i < MAGIC_LENGTH)
	{
		temp = temp << 8;	
		temp |= s[i];
		i++;
	}
	magic = (int)temp;
	if (magic != COREWAR_EXEC_MAGIC)
		error("Invalid magic header", 0);
}

/*
**	@desc	- this function gets the program name and checks for errors
**	@param	- t_dsm *data, main struct
*/

static void	get_prog_name(t_dsm *data)
{
	unsigned char	s[PROG_NAME_LENGTH];
	int				ret;

	ret = read(data->rfd, s, PROG_NAME_LENGTH);
	if (ret < PROG_NAME_LENGTH)
		error("Invalid program name", 0);
	data->name = ft_strdup((char*)s);
}

/*
**	@desc	- main parsing function
**	@param	- t_dsm *data, main struct
*/

void		parse(t_dsm *data)
{
	get_magic_header(data);
	get_prog_name(data);
}