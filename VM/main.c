/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 15:26:21 by krioliin       #+#    #+#                */
/*   Updated: 2019/12/30 20:32:45 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

int		main(int argc, char **argv)
{
	t_vm		*vm;

	if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		return (0);
	if (!(vm->flag = (t_flags *)ft_memalloc(sizeof(t_flags))))
		return (0);
	if (!args_validation(argc, argv, vm->flag))
		parse_error();
	if (!init_players(vm))
		ft_printf("Can't init players\n");
	if (!init_battlefield(vm))
		ft_printf("Error battlefield\n");
	if (vm->flag->v)
		visual_corawar(vm);
	vm_free(&vm);
	return (0);
}
