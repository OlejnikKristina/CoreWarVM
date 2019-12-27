/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 15:26:21 by krioliin       #+#    #+#                */
/*   Updated: 2019/12/27 16:57:16 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm_arena.h"

int		main(int argc, char **argv)
{
	t_vm		*vm;

	if (!(vm = (t_vm *)ft_memalloc(sizeof(t_vm))))
		return (0);
	if (!(vm->flag = (t_flags *)ft_memalloc(sizeof(t_flags))))
		return (0);
	if (!args_validation(argc, argv, vm->flag))
		parse_error();
	else if (!init_players(vm))
		ft_printf("Can't init players\n");
	else
		ft_printf("Arguments are correct!\n");
	// ft_printf("N: %s\n", vm->flag->players_order[0]);
	// ft_printf("N: %s\n", vm->flag->players_order[1]);
	// ft_printf("N: %s\n", vm->flag->players_order[2]);
	// ft_printf("N: %s\n", vm->flag->players_order[3]);
	vm_free(&vm);
	// sleep(20);
	test_reg();
	return (0);
}
