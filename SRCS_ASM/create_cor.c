/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:52:45 by abumbier          #+#    #+#             */
/*   Updated: 2019/12/17 17:21:22 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

//before writing anything swap the coresponding bits

void		write_null_bytes(int n, int wfd)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(wfd, "\0", 1);
		i++;
	}
}

void		create_cor(t_asm *data)
{
	char	*name;
	char	**split;

	split = ft_strsplit(data->char_name, '.');
	name = ft_strjoin(split[0], ".cor");
	free_arr(NULL, &split, 1);
//	ft_printf("\t\t\tcname %s\n", name);									//REMOVE
	data->wfd = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	write_cor_file(data);
	ft_strdel(&name);
}
