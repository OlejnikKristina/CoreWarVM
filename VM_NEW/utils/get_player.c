/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_player.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 12:30:18 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/29 14:31:56 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

int		get_player(t_vm *vm, t_champ *champs, int id)
{
	int		i;

	i = 0;
	while (i < NB_PLAYERS)
	{
		if (champs[i].id == id)
			return (i);
		i++;
	}
	return (-1);
}
