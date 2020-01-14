/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vinit_cursors.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 14:39:50 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/13 13:51:46 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_visual.h"

// t_vcursor	*vinit_cursor(t_cursor *classic_cursor)
// {
// 	t_vcursor *new_cursor;

// 	new_cursor = (t_vcursor *)ft_memalloc(sizeof(t_cursor));
// 	new_cursor->id =
// 	new_cursor->next = NULL;
// 	return (NULL);
// }

// t_vcursor	*vinit_cursors(t_vcursor *vcursors, t_cursor *cursors)
// {
// 	t_cursor	*cursor;
// 	t_vcursor	*vcursor;

// 	cursor = cursors;
// 	vcursor = new_visual_cursor();
// 	while (cursor)
// 	{
// 		vcursor->next = new_visual_cursor();
// 		cursor = cursor->next;
// 		vcursor = vcursor->next;
// 	}
// 	return (NULL);
// }

// void	init_cursors_coordinats(t_cursor *cursors, short players_amnt)
// {
// 	t_cursor	*cursor;
// 	int			next_player;
// 	int			y;
// 	int			i;
// 	int			x;

// 	i = players_amnt - 1;
// 	cursor = cursors;
// 	while (cursor)
// 	{
// 		if (i != 0)
// 			x = cursor->pos % 64;
// 		else
// 			x = cursor->pos;
// 		if (64 <= x)
// 		{
// 			y = x / 64;
// 			x %= 64;
// 		}
// 		else
// 			y = 0;
// 		next_player = ((HEIGHT) / players_amnt) * i;
// 		cursor->xy[0] = x * 3 + 3;
// 		cursor->xy[1] = OFFSETY + 1 + next_player + y - i;
// 		cursor = cursor->next;
// 	}
// }
