/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_player.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 12:30:18 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/23 12:33:26 by asulliva      ########   odam.nl         */
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
	error("Player not found", NULL);
	return (-1);
}
