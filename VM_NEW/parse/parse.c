/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 15:30:19 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/28 18:50:06 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function checks if file is valid champion
**	@param	- char *file, file to check
**	@return	- 1 if champ, 0 if not
*/

static int	is_champ(char *file)
{
	if (check_name(file) && check_file(file))
		return (1);
	return (0);
}

/*
**	@desc	- function counts number of champs in arguments
**	@param	- char **av, arguments
**	@return	- number of champs in arguments
*/

static int	nb_champs(char **av)
{
	int		i;
	int		nb_champs;

	i = 0;
	nb_champs = 0;
	while (av[i])
	{
		if (is_champ(av[i]))
			nb_champs++;
		i++;
	}
	if (MAX_PLAYERS < nb_champs)
		error("Max 4 players", NULL);
	if (!nb_champs)
		error("usage", NULL);
	return (nb_champs);
}

/*
**	@desc	- function checks if incoming args are correct
**	@param	- char **av, arguments
**			- int ac, amount of arguments
*/

static void	check_args(char **av, int ac)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!(!ft_strcmp(av[i], "-n") || !ft_strcmp(av[i], "-dump")
		|| !ft_strcmp(av[i], "-v") || (format_check("%d", av[i])
		&& (!ft_strcmp(av[i - 1], "-dump") || !ft_strcmp(av[i - 1], "-n")))
		|| check_name(av[i])))
			error("Invalid argument", NULL);
		i++;
	}
}

/*
**	@desc	- main parsing function
**	@param	- t_vm *vm, main struct
**			- int ac, nb of arguments
**			- char **av, the arguments
*/

void		parse(t_vm *vm, int ac, char **av)
{
	check_args(av, ac);
	NB_PLAYERS = nb_champs(av);
	CHAMPS = (t_champ*)ft_memalloc(sizeof(t_champ) * NB_PLAYERS);
	flags(vm, ac, av);
	get_champs(vm, av, ac);
	if (FLAG->n)
		switch_champs(vm, ac, av);
}
