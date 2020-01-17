/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm_free.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/22 11:27:33 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/16 20:09:21 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

void	cursors_free(t_cursor *cursor)
{
	if (cursor)
	{
		cursors_free(cursor->next);
		ft_memdel((void **)&cursor);
	}
}

void	players_free(t_vm **vm)
{
	int		i;

	i = 0;
	if (!(*vm)->players)
		return ;
	while (i < (*vm)->players_amnt)
	{
		free((*vm)->players[i]->name);
		ft_bzero((*vm)->players[i], sizeof(*vm)->players[i]);
		if ((*vm)->players[i]->code)
			ft_memdel((void **)&(*vm)->players[i]->code);
		free((*vm)->players[i]);
		(*vm)->players[i] = NULL;
		i++;
	}
	ft_bzero((*vm)->players, sizeof(*vm)->players);
	free((*vm)->players);
	(*vm)->players = NULL;
}

void	vm_free(t_vm **vm)
{
	if (*vm)
	{
		players_free(vm);
		if ((*vm)->cursor)
			cursors_free((*vm)->cursor);
		if ((*vm)->flag->v)
		{
			getch();
			delwin((*vm)->v->warena);
			delwin((*vm)->v->winfo);
			delwin((*vm)->v->wop);
			endwin();
		}
		if ((*vm)->flag)
		{
			ft_bzero((void *)(*vm)->flag, sizeof((*vm)->flag));
			free((*vm)->flag);
			(*vm)->flag = NULL;
		}
		ft_bzero((void *)*vm, sizeof(*vm));
		ft_memdel((void **)vm);
	}
}
