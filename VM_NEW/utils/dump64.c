/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dump64.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:51:18 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/26 17:27:37 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

static char	*get_hex(int n, int len)
{
	char	*ret;
	char	padding[4];
	int		offset;
	int		i;

	ret = itoa_base64u(n, 16, 0);
	offset = (2 * len) - ft_strlen(ret);
	i = 0;
	while (i < offset)
	{
		padding[i] = '0';
		i++;
	}
	padding[i] = 0;
	ret = ft_strjoin(padding, ret);
	return (ret);
}

int			dump64(t_vm *vm)
{
	int i;
	int j;
	int idx;
	int line;

	i = 0;
	line = 0;
	idx = 0;
	while (i < 64)
	{
		j = 0;
		ft_printf("0x%s : ", get_hex(line, 2));
		while (j < 64)
		{
			ft_printf("%s ", get_hex(vm->arena[idx], 1));
			idx++;
			j++;
		}
		ft_putendl("");
		line += 64;
		i++;
	}
	exit(0);
	return (1);
}
