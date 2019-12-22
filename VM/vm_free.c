/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm_free.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/22 11:27:33 by krioliin       #+#    #+#                */
/*   Updated: 2019/12/22 12:09:47 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vm_arena.h"

void	players_free(t_vm **vm)
{
	int		i;

	i = 0;
	if (!(*vm)->players)
		return ;
	while (i < (*vm)->players_amnt)
	{
		ft_bzero((*vm)->players[i], sizeof(*vm)->players[i]);
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
