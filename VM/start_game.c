/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_game.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 15:28:07 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/15 16:06:14 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/vm_arena.h"

int		bury_dead_cursors(t_cursor **head)
{
	int			corpse_counter;
	t_cursor	*cursor;
	t_cursor	*prev;

	if (!head || (*head)->last_live == 0)
	{
		ft_memdel((void **)head);
		// ft_printf("%{RED}ALL PLAYERS DEAD\n%{RESET}");
		return (100);
	}
	(*head)->last_live = 0;
	corpse_counter = 0;
	prev = *head;
	cursor = (*head)->next;
	while (cursor)
	{
		if (cursor->last_live == 0)
		{
			prev->next = cursor->next;
			ft_memdel((void **)&cursor);
			corpse_counter++;
			if (prev->next == NULL)
				break ;
		}
		else
		{
			cursor->last_live = 0;
			cursor = cursor->next;
			prev = cursor;
		}
	}
	return(corpse_counter);
}

bool		check(t_vm *vm)
{
	static int checks_in_row;

	checks_in_row++;
	if (NBR_LIVE <= vm->nbr_lives || MAX_CHECKS <= checks_in_row)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		checks_in_row = 0;
	}
	vm->nbr_lives = 0;
	vm->process -= bury_dead_cursors(&vm->cursor);
	return (0 < vm->process);
}

bool	execute_one_cycle(t_vm *vm)
{
	t_cursor	*cursor;

	cursor = vm->cursor;
	while (cursor)
	{
		execute_cursor(cursor, vm->arena, vm);
		cursor = cursor->next;
	}
	if (vm->flag->v)
		refresh_arena(vm);
	return (true);
}

char	*get_hex(int n, int len)
{
	char	*ret;
	char	padding[4];
	int		offset;
	int		i;

	ret = itoa_base64u(n, 16, 0);
	offset = (2 * len) - ft_strlen(ret);
	i = 0;
	while (i < offset)
	{
		padding[i] = '0';
		i++;
	}
	padding[i] = 0;
	ret = ft_strjoin(padding, ret);
	return (ret);
}

bool	dump64(t_vm *vm)
{
	int i;
	int j;
	int idx;
	int line;

	i = 0;
	line = 0;
	idx = 0;
	while (i < 64)
	{
		j = 0;
		ft_printf("0x%s : ", get_hex(line, 2));
		while (j < 64)
		{
			ft_printf("%s ", get_hex(vm->arena[idx], 1));
			idx++;
			j++;
		}
		ft_putendl("");
		line += 64;
		i++;
	}
	exit(0);
	return (true);
}

bool	up_to_cycle_to_die(t_vm *vm)
{
	bool		someone_alive;
	static int	cycle_counter;

	someone_alive = true;
	while (someone_alive)
	{
		vm->current_cycle = 0;
		while (vm->current_cycle <= vm->cycle_to_die)
		{
			execute_one_cycle(vm);
			cycle_counter++;
			vm->current_cycle += 1;
			if (vm->flag->hexdump == cycle_counter)
				return (show_arena(vm->players, vm->players_amnt, vm));
			else if (vm->flag->dump == cycle_counter)
				return (dump64(vm));
		}
		someone_alive = check(vm);
	}
	return (true);
}

bool	start_game(t_vm *vm)
{
	t_player *the_champion;

	up_to_cycle_to_die(vm);
	the_champion = get_player_by_id(vm->players, vm->last_alive, vm->players_amnt);
	if (vm->flag->v == false)
		ft_printf("Contestant %d, \"%s\", has won !\n", vm->last_alive, the_champion->name);
	return (true);
}
