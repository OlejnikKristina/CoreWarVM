/* ************************************************************************** */
/*                                                                            */
<<<<<<< HEAD
/*                                                        ::::::::            */
/*   create_cor.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 17:52:45 by abumbier       #+#    #+#                */
/*   Updated: 2019/12/14 15:34:23 by asulliva      ########   odam.nl         */
=======
/*                                                        :::      ::::::::   */
/*   create_cor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:52:45 by abumbier          #+#    #+#             */
/*   Updated: 2019/12/13 19:05:34 by abumbier         ###   ########.fr       */
>>>>>>> abumbier
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

<<<<<<< HEAD
//before writing anything swap the coresponding bits

// void		write_cor(t_asm *data)
// {
	
// }
=======
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

}
>>>>>>> abumbier

void		create_cor(t_asm *data)
{
	char	*name;
	char	**split;

	split = ft_strsplit(data->char_name, '.');
	name = ft_strjoin(split[0], ".cor");	//memberberries to free
	free_arr(NULL, &split, 1);
	ft_printf("\t\t\tcname %s\n", name);
	data->wfd = open(name, O_WRONLY | O_APPEND | O_CREAT, 0777);
	write_cor_file(data);
	ft_strdel(&name);
}
