/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dump64.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/15 16:34:09 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/15 16:36:57 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

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

bool		dump64(t_vm *vm)
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
	return (false);
}
