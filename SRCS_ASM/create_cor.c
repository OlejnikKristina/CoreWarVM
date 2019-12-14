/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_cor.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 17:52:45 by abumbier       #+#    #+#                */
/*   Updated: 2019/12/14 14:10:53 by asulliva      ########   odam.nl         */
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

	ft_printf("\t\t\tchar_name %s\n", data->char_name);
	name = ft_strjoin(data->char_name, ".cor");	//memberberries to free
	ft_printf("\t\t\tcname %s\n", name);
	data->wfd = open(name, O_WRONLY | O_APPEND | O_CREAT, 0777);
	ft_strdel(&name);
}
