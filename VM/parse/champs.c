/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   champs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 16:58:48 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/28 15:41:30 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function checks magic header in file
**	@param	- const int fd, file descriptor
**	@return	- 0 on error, !0 on succes
*/

static int		magic_header(const int fd)
{
	int		ret;
	int		h_in;
	int		h_ref;

	if (read(fd, &ret, 4) < 4)
		return (0);
	h_ref = COREWAR_EXEC_MAGIC;
	h_in = swap_32(ret);
	return (h_ref == h_in);
}

/*
**  @desc   - function checks for nullbytes in file
**  @param  - const int fd, file descriptor
**  @return - 0 on error, !0 on succes
*/

static int		null_byte(const int fd)
{
	int		ret;
	char	*tab;

	if (read(fd, &ret, 4) < 4)
		return (0);
	tab = (char*)&ret;
	return (tab[0] == 0 &&
	tab[1] == 0 && tab[2] == 0
	&& tab[3] == 0);
}

/*
**	@desc	- function checks if the code size is correct
**	@param	- t_champ *champ, pointer to champion
**			- const int fd, file descriptor for champ
**	@return	- 1 on success, 0 on error
*/

static int		get_champ_size(t_champ *champ, const int fd)
{
	int		ret;

	if (read(fd, &ret, 4) < 4)
		return (0);
	ret = swap_32(ret);
	if (CHAMP_MAX_SIZE < ret)
		return (0);
	champ->size = ret;
	return (1);
}

/*
**	@desc	- funcion reads file and inits champ
**	@param	- t_vm *vm, main struct
**			- char *file, file parsin atm
**			- int fd, filedescriptor, allways 0
**	@return	- t_champ champ, initialized champ
*/

static t_champ	read_file(t_vm *vm, char *file, int fd)
{
	t_champ	new;
	t_byte	*code;

	fd = open((const char*)file, O_RDONLY);
	if (fd < 3)
		error("Parsing champ", file);
	if (!magic_header(fd))
		error("Invalid magic header in ", file);
	if (!get_champ_name(&new, fd))
		error("Getting champ name ", file);
	if (!null_byte(fd))
		error("No nullbytes in the right places ", file);
	if (!get_champ_size(&new, fd))
		error("Invalid champ size in ", file);
	if (!get_champ_comment(&new, fd))
		error("Getting champ comment ", file);
	if (!null_byte(fd))
		error("No nullbytes in the right places ", file);
	code = ft_memalloc(sizeof(t_byte) * new.size);
	read(fd, code, new.size);
	if (!check_code(vm, &new, code))
		error("Invalid executable code for ", file);
	free(code);
	close(fd);
	return (new);
}

/*
**	@desc	- main function to get champions
**	@param	- t_vm *vm, main struct
**			- char **av, arguments
**			- int ac, number of arguments
*/

void			get_champs(t_vm *vm, char **av, int ac)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (check_name(av[i]))
			CHAMPS[vm->champ_id - 1] = read_file(vm, av[i], 0);
		i++;
	}
}
