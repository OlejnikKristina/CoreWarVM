/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 18:51:51 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/05 18:52:30 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	parse_command(t_asm *data, char *s)
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

void		get_name_comment(t_asm *data)
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
