/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_champ.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 17:20:39 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/28 16:37:03 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function gets champ name out of file
**	@param	- t_champ *champ, pointer to champ
**			- const int fd, file descriptor
**	@return	- 1 on success, 0 on error
*/

int			get_champ_name(t_champ *champ, const int fd)
{
	char	champ_name[PROG_NAME_LENGTH + 1];

	ft_bzero(champ_name, PROG_NAME_LENGTH + 1);
	if (read(fd, champ_name, PROG_NAME_LENGTH) >= PROG_NAME_LENGTH)
	{
		champ->name = ft_strdup(champ_name);
		return (1);
	}
	return (0);
}

/*
**	@desc	- function gets champ comment out of file
**	@param	- t_champ *champ, pointer to champ
**			- const int fd, file descriptor
**	@return	- 1 on success, 0 on error
*/

int			get_champ_comment(t_champ *champ, const int fd)
{
	char	champ_comment[COMMENT_LENGTH + 1];

	ft_bzero(champ_comment, COMMENT_LENGTH + 1);
	if (read(fd, champ_comment, COMMENT_LENGTH) >= COMMENT_LENGTH)
	{
		champ->comment = ft_strdup(champ_comment);
		return (1);
	}
	return (0);
}

/*
**	@desc	- functions checks the exec code for errors
**	@param	- int *code, exec code
**			- int size, size of the code
**	@return	- 1 on success, 0 on error
*/

int			check_code(t_vm *vm, t_champ *c, t_byte *code)
{
	c->start_pos = (MEM_SIZE / NB_PLAYERS) * (vm->champ_id - 1);
	ft_memcpy(&ARENA[c->start_pos], code, c->size);
	c->id = vm->champ_id;
	c->lives = 0;
	c->last_live = 0;
	vm->champ_id++;
	return (1);
}
