/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 16:08:15 by asulliva       #+#    #+#                */
/*   Updated: 2019/09/11 16:08:35 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstrev(t_list **list)
{
	t_list	*now;
	t_list	*next;

	next = *list;
	if (*list)
	{
		next = next->next;
		(*list)->next = NULL;
		while (next)
		{
			now = next;
			next = next->next;
			now->next = *list;
			*list = now;
		}
	}
}
