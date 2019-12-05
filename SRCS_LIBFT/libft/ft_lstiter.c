/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 17:47:44 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/23 17:47:45 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*element;

	element = lst;
	if (lst != NULL || f != NULL)
	{
		while (element)
		{
			f(element);
			element = element->next;
		}
	}
}
