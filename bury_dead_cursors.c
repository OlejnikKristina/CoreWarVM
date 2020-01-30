/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bury_dead_cursors.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 21:07:09 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/30 21:08:18 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "vm_arena.h"

static t_cursor	*rm_first_dead_cursors(t_cursor **head, int *corpse_counter)
{
	t_cursor	*prev;

	prev = *head;
	*corpse_counter = 0;
	while (prev && prev->last_live == 0)
	{
		*head = prev->next;
		ft_memdel((void **)&prev);
		if (*head == NULL)
			return (NULL);
		prev = *head;
		corpse_counter++;
	}
	prev->last_live = 0;
	return (prev);
}

int			bury_dead_cursors(t_cursor **head)
{
	int			corpse_counter;
	t_cursor	*cursor;
	t_cursor	*prev;

	prev = rm_first_dead_cursors(head, &corpse_counter);
	if (prev == NULL)
		return (100);
	cursor = prev->next;
	while (cursor)
	{
		if (cursor->last_live <= 0)
		{
			prev->next = cursor->next;
			ft_memdel((void **)&cursor);
			corpse_counter++;
			if (prev == NULL)
				break ;
		}
		else
			cursor->last_live = 0;
		prev = prev->next;
		if (prev == NULL)
			break ;
		cursor = prev->next;
	}
	return(corpse_counter);
}
