/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_arena.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 19:30:09 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/15 16:36:49 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

static int get_cursor_pos(t_cursor *cursor_head, int id)
{
	t_cursor *cursor;

	cursor = cursor_head;
	while (cursor)
	{
		if (cursor->id == id)
			return (cursor->pos);
		cursor = cursor->next;
	}
	return (0);
}

static void show_additional_info(t_vm *vm)
{
	ft_printf("%{BLUE_B}   Processes: %d\n", vm->process);
	ft_printf("   Last_alive: %d\n", vm->last_alive);
	ft_printf("   nbr_lives: %d\n", vm->nbr_lives);
	ft_printf("   current_cycle: %d\n", vm->current_cycle);
	ft_printf("   cycle_to_die: %d\n\n", vm->cycle_to_die);
}

bool	show_arena(t_player **players, short pl_amnt, t_vm *vm)
{
	int		i;
	short	z;
	int		index;

	i = 0;
	z = 0;
	index = MEM_SIZE / pl_amnt;
	show_additional_info(vm);
	write(1, "\n     ", 7);
	while (i < MEM_SIZE)
	{
		if (get_cursor_pos(vm->cursor, 1) == i)
			ft_printf("%{RED_B}%.2x %{GRAY_B}", vm->arena[i]);
		else if (1 < vm->process && get_cursor_pos(vm->cursor, 2) == i)
			ft_printf("%{RED_B}%.2x %{GRAY_B}", vm->arena[i]);
		else if (2 < vm->process && get_cursor_pos(vm->cursor, 3) == i)
			ft_printf("%{RED_B}%.2x %{GRAY_B}", vm->arena[i]);
		else if (3 < vm->process && get_cursor_pos(vm->cursor, 4) == i)
			ft_printf("%{RED_B}%.2x %{GRAY_B}", vm->arena[i]);
		else if (4 < vm->process && get_cursor_pos(vm->cursor, 4) == i)
			ft_printf("%{RED_B}%.2x %{GRAY_B}", vm->arena[i]);

		else if (0 <= i && i < index && i < players[0]->code_size)
			ft_printf("%{PINK_B}%.2x %{GRAY_B}", vm->arena[i]);

		else if (1 < pl_amnt && index < i && i < index * 2 &&
		i <= (players[1]->code_size + index))
			ft_printf("%{YELLOW_B}%.2x%{GRAY_B} ", vm->arena[i]);
		else if (2 < pl_amnt && index * 2 <=i && i < index * 3 &&
		i <= (players[2]->code_size + index * 2))
			ft_printf("%{BLUE_B}%.2x%{GRAY_B} ", vm->arena[i]);
		else if (3 < pl_amnt && index * 3 < i && i < index * 4 &&
		i <= (players[3]->code_size + index * 3))
			ft_printf("%{GREEN_B}%.2x%{GRAY_B} ", vm->arena[i]);
		else
			ft_printf("%.2x%{GRAY_B} ", vm->arena[i]);
		if ((i + 1) % 64 == 0 && i != 0)
			ft_printf("\n     ");
		i++;
	}
	ft_printf("%{RESET}\n");
	return (0);
}
