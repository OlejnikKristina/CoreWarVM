/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 14:17:50 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/05 16:49:00 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_lines	*make_line(char **s)
{
	t_lines	*new;

	new = ft_memalloc(sizeof(t_lines));
	new->next = NULL;
	new->line = ft_strdup(*s);
	return (new);
}

void	set_line(t_asm *data, t_lines *new)
{
	t_lines	*curr;

	curr = data->file;
	while (curr)
		curr = curr->next;
	curr = new;
	// ft_printf("curr->line %s\n", curr->line);
}

void	readfile(t_asm *data)
{
	t_lines		*curr;

	data->file = (t_lines*)ft_memalloc(sizeof(t_lines));
	while (get_next_line(data->rfd, &data->content))
	{
		curr = make_line(&data->content);
		ft_printf("curr->line %s\n", curr->line);
		set_line(data, curr);
	}
}

t_asm	*init(int ac, char **av)
{
	t_asm	*data;

	data = (t_asm*)ft_memalloc(sizeof(t_asm));
	data->rfd = open(av[ac - 1], O_RDONLY);
	if (data->rfd < 3 || read(data->rfd, data->content, 0) < 0)
		return (NULL);
	return (data);
}

void	printfile(t_lines *file)
{
	t_lines	*curr;

	curr = file;
	ft_printf("print\t\t%2p\n", curr);
	while (curr->next)
	{
		ft_putendl(curr->line);
		curr = curr->next;
	}
}

int		main(int ac, char **av)
{
	t_asm	*data;

	if (ac < 2)
		error("usage ./asm <file_name>");
	data = init(ac, av);
	if (!data)
		error("Invalid file");
	readfile(data);
	// ft_printf("main\t\t%2p\n", data->file);
	printfile(data->file);
	return (0);
}