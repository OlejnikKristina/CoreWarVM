/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:17:50 by asulliva          #+#    #+#             */
/*   Updated: 2019/12/14 16:15:25 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	@desc	- initialized the file to be opened
**	@param	- int ac, the number of arguments
**			- char **av, the arguments
**	@return	- t_asm *data, open file and malloced struct
*/

static t_asm	*init(int ac, char **av)
{
	t_asm	*data;

	data = (t_asm*)ft_memalloc(sizeof(t_asm));
	data->parts = NULL;
	data->labels = NULL;
	data->lines = 0;
	data->char_name = av[ac - 1];
	data->rfd = open(av[ac - 1], O_RDONLY);
	if (data->rfd < 3 || read(data->rfd, data->name, 0) < 0)
		return (NULL);
	return (data);
}

/*
**	@desc	- main controller function
**	@param	- int ac, the number of arguments
**			- char **av, the arguments
**	@return	- 0
*/

int				main(int ac, char **av)
{
	t_asm	*data;
	t_label	*curr;
	t_parts	*curr_part;

	if (ac < 2)
		error("usage ./asm <file_name>", 0);
	data = init(ac, av);
	if (!data)
		error("Invalid file", 0);
	parse(data);
	close(data->rfd);
	calc_line_byte(data);
	curr = data->labels;
	while (curr)
	{
		ft_printf("%-15s\tline %d\n", curr->name, curr->line);
		curr = curr->next;
	}
	curr_part = data->parts;
	while (curr_part)
	{
		ft_printf("%-10s : %-15d = %-10d\tline %d\n", curr_part->name, curr_part->token, curr_part->value, curr_part->line);
		curr_part = curr_part->next;
	}
//	check_syntax(data->parts);
	create_cor(data);
	ft_printf("og: %d\nsw: %d\n", 0xea83f300, swap_4_bytes(0xea83f300));
	ft_printf("og: %hd\nsw: %hd\n", 11, swap_2_bytes(11));
	free_data(data);
	return (0);
}
