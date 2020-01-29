/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:24:02 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/29 17:40:03 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm_arena.h"

/*
**	@desc	- function initializes VM struct
**	@return	- t_vm *new, freshly malloced struct
*/

static t_vm	*init(void)
{
	t_vm	*new;

	new = ft_memalloc(sizeof(t_vm));
	new->flag = ft_memalloc(sizeof(t_flags));
	new->champ_id = 1;
	if (!new || !new->flag)
		error("Malloc error", NULL);
	new->flag->dump = -1;
	return (new);
}

int			main(int ac, char **av)
{
	t_vm	*vm;

	vm = init();
	parse(vm, ac, av);
	init_game(vm);
	start_game(vm);
	free_vm(vm);
}
