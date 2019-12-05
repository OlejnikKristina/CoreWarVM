/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 13:19:12 by awehlbur       #+#    #+#                */
/*   Updated: 2019/07/11 17:13:17 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*element;

	element = (t_list*)malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	if (content == NULL)
	{
		element->content = NULL;
		element->content_size = 0;
	}
	else
	{
		element->content = ft_memalloc(content_size);
		ft_memcpy(element->content, content, content_size);
		element->content_size = content_size;
	}
	element->next = NULL;
	return (element);
}
