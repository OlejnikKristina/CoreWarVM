/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 14:17:50 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/05 18:49:29 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_asm	*init(int ac, char **av)
{
	t_asm	*data;

	data = (t_asm*)ft_memalloc(sizeof(t_asm));
	data->rfd = open(av[ac - 1], O_RDONLY);
	if (data->rfd < 3 || read(data->rfd, data->content, 0) < 0)
		return (NULL);
	return (data);
}

void	parse_command(t_asm *data, char *s)
{
	char	*temp;
	char	*command;

	temp = ft_strchr(s, ' ');
	command = ft_strndup(s, ft_strlen(s) - ft_strlen(temp));
	temp = ft_strtrim(temp);
	command = ft_strtrim(command);
	if (!ft_strcmp(command, ".name"))
		data->name = ft_strdup(temp);
	else if (!ft_strcmp(command, ".comment"))
		data->comment = ft_strdup(temp);
	else
		error("Invalid command");
}

void	get_name_comment(t_asm *data)
{
	t_lines	*curr;

	curr = data->file;
	while (curr)
	{
		if (curr->line && curr->line[0] == '.')
			parse_command(data, curr->line);
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
	get_name_comment(data);
	ft_printf("name = %s\ncomment = %s\n", data->name, data->comment);
	return (0);
}
