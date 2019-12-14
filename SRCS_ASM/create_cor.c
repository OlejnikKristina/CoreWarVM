/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_cor.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 17:52:45 by abumbier       #+#    #+#                */
/*   Updated: 2019/12/14 15:52:12 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

//before writing anything swap the coresponding bits

// void		write_cor(t_asm *data)
// {
	
// }

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
