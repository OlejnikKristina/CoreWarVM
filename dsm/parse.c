/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 15:55:51 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/29 18:58:33 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/dsm.h"

/*
**	@desc	- this function checks the magic header in the file
**	@param	- t_dsm *data, main struct
*/

static void	get_magic_header(t_dsm *data)
{
	unsigned char	s[4 + 1];
	int				magic;

	magic = read(data->rfd, (void*)s, 4);
	if (magic < 4)
		error("File is corrupted\nMight be the magic header", 0);
	magic = convert(s, 4);
	if (magic != COREWAR_EXEC_MAGIC)
		error("File is corrupted\nMight be the magic header", 0);
}

/*
**	@desc	- this function gets the program name and checks for errors
**	@param	- t_dsm *data, main struct
*/

static void	get_prog_name(t_dsm *data)
{
	unsigned char	s[PROG_NAME_LENGTH + 1];
	int				ret;

	ret = read(data->rfd, s, PROG_NAME_LENGTH);
	if (ret < PROG_NAME_LENGTH)
		error("File is corrupted\nMight be the program name", 0);
	data->name = ft_strdup((char*)s);
}

/*
**	@desc	- function gets the size out of the file
**	@param	- t_dsm *data, main struct
*/

static void	get_size(t_dsm *data)
{
	unsigned char	s[8];
	int				ret;

	ret = read(data->rfd, s, 8);
	if (ret < 8 || ((int*)s)[0])
		error("File is corrupted\nMight be the size", 0);
	data->size = convert(&s[4], sizeof(int));
}

/*
**	@desc	- function gets the comment out of the file
**	@param	- t_dsm *data, main struct
*/

static void	get_comment(t_dsm *data)
{
	unsigned char	s[COMMENT_LENGTH + 1];
	int				ret;

	ret = read(data->rfd, s, COMMENT_LENGTH);
	if (ret < COMMENT_LENGTH)
		error("File is corrupted\nMight be the comment", 0);
	data->comment = ft_strdup((char*)s);
	ret = read(data->rfd, s, 4);
	if (ret < 4 || ((int*)s)[0])
		error("File is corrupted\nMight not end in NULL bytes", 0);
}

/*
**	@desc	- main parsing function
**	@param	- t_dsm *data, main struct
*/

void		parse(t_dsm *data)
{
	get_magic_header(data);
	get_prog_name(data);
	get_size(data);
	get_comment(data);
	get_exec_code(data);
}
