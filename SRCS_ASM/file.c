/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 18:09:23 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/05 18:10:03 by asulliva      ########   odam.nl         */
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
