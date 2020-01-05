/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 15:26:21 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/05 15:50:33 by krioliin      ########   odam.nl         */
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
	if (!init_cursors(vm))
		ft_printf("Error battlefield\n");
	start_game(vm);
	if (vm->flag->v)
		visual_corawar(vm);
	vm_free(&vm);
	return (0);
}
