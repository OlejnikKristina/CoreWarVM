/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 14:17:50 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/05 18:07:54 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_lines	*make_line(char *s)
{
	t_lines	*new;

	new = malloc(sizeof(t_lines));
	new->line = ft_strdup(s);
	new->next = NULL;
	return (new);
}

void	copy_line(t_asm *data, char *s)
{
	t_lines	*curr;

	curr = data->file;
	while (curr->next)
		curr = curr->next;
	curr->next = make_line(s);
}

void	init_file(t_asm *data)
{
	data->file = malloc(sizeof(t_lines));
	data->file->line = NULL;
	data->file->next = NULL;
}

void	readfile(t_asm *data)
{
	init_file(data);
	while (get_next_line(data->rfd, &data->content))
		copy_line(data, data->content);
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

void	printfile(t_asm *data)
{
	t_lines	*curr;

	curr = data->file;
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
	printfile(data);
	return (0);
}