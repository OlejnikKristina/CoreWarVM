/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:52:45 by abumbier          #+#    #+#             */
/*   Updated: 2019/12/14 16:14:25 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*get_cor_name(char *str)
{
	char		*new;
	char		*append;
	size_t		len;

	len = ft_strlen(str);
	new = ft_memalloc(len + 3);
	append = ft_memccpy(new, str, '.', len - 1);
	append = ft_memccpy(append, "cor", 'r', 3);
	*append = '\0';
	return (new);
}

/*
** @descr	- appends n amount of bytes to the file.
*/

void		write_null_bytes(int n, int wfd)
{
	write(wfd, '\0', n);
}

void		create_cor(t_asm *data)
{
	char	*name;

	name = get_cor_name(data->char_name);	//memberberries to free
	data->wfd = open(name, O_WRONLY | O_APPEND | O_CREAT, 0777);
	write_cor_file(data);
	ft_strdel(&name);
}
