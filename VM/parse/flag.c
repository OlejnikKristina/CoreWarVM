/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:54:25 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/28 18:53:46 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function checks for n_flag
**	@param	- t_vm *vm, main struct
**			- int ac, amount of args
**			- char **av, arguments
**			- int i, nb_arg we at now
*/

static void		n_flag(t_vm *vm, char **av, int ac, int i)
{
	if (i >= ac - 1 || !format_check("%d", av[i + 1]))
		error("-n flag needs numeric value", NULL);
	if (NB_PLAYERS < ft_atoi(av[i + 1]))
		error("value for -n flag larger than number of players ", av[i + 1]);
	FLAG->n = 1;
}

/*
**	@desc	- function sets all champs with n-flag
**	@param	- t_vm *vm, main struct
**			- int ac, amount of args
**			- char **av, arguments
**	@return	- t_champ *new, new malloced and filled array
*/

static t_champ	*set_nflag(t_vm *vm, int ac, char **av)
{
	int			i;
	int			idx;
	int			n;
	t_champ		*new;

	new = ft_memalloc(sizeof(t_champ) * NB_PLAYERS);
	idx = 0;
	i = 0;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-n"))
		{
			n = ft_atoi(av[i + 1]) - 1;
			if (new[n].name)
				error("Invalid use of the -n flag", NULL);
			new[n] = CHAMPS[idx];
			new[n].id = n + 1;
		}
		if (check_name(av[i]))
			idx++;
		i++;
	}
	return (new);
}

/*
**	@desc	- function swaps champs around according to n-flag
**	@param	- t_vm *vm, main struct
**			- int ac, amount of args
**			- char **av, arguments
*/

void			switch_champs(t_vm *vm, int ac, char **av)
{
	int			i;
	int			idx;
	int			nb_arg;
	t_champ		*new;

	new = set_nflag(vm, ac, av);
	idx = 0;
	while (new[idx].name)
		idx++;
	i = 0;
	nb_arg = 0;
	while (i < ac)
	{
		if ((!av[i - 2] ||
		(i - 2 > -1 && ft_strcmp(av[i - 2], "-n"))) && check_name(av[i]))
		{
			new[idx] = CHAMPS[nb_arg];
			new[idx].id = idx + 1;
			idx++;
		}
		if (check_name(av[i]))
			nb_arg++;
		i++;
	}
	CHAMPS = new;
}

/*
**	@desc	- function parses the flags
**	@param	- t_vm *vm, main struct
**			- int ac, amount of args
**			- char **av, arguments
*/

void			flags(t_vm *vm, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-dump"))
		{
			if (i >= ac - 1)
				error("-dump flag needs numeric value", NULL);
			if (ft_atoi(av[i + 1]) < 0)
				error("Invalid value for -dump", av[i + 1]);
			FLAG->dump = ft_atoi(av[i + 1]);
		}
		else if (!ft_strcmp(av[i], "-v"))
			FLAG->v = 1;
		else if (!ft_strcmp(av[i], "-n"))
			n_flag(vm, av, ac, i);
		i++;
	}
}
