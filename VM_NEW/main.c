/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:24:02 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/26 17:28:02 by asulliva      ########   odam.nl         */
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

void	print_champs(t_champ *c, int max)
{
	int		i;

	i = 0;
	while (i < max)
	{
		ft_printf("%{YELLOW}.name [%s]\n.comment [%s]\nid [%d]\nsize [%d]\nlives [%d]\nlast_live [%d]\n%{WHITE}",
			c[i].name, c[i].comment, c[i].id, c[i].size, c[i].lives, c[i].last_live);
		i++;
	}
}

int			main(int ac, char **av)
{
	t_vm	*vm;

	vm = init();
	parse(vm, ac, av);
	// print_champs(CHAMPS, NB_PLAYERS);
	init_game(vm);
	start_game(vm);
}
