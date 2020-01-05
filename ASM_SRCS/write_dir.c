/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_dir.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 19:44:42 by abumbier       #+#    #+#                */
/*   Updated: 2020/01/05 17:00:17 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

static char	*clean_label(char *label)
{
	char	*new;
	int		i;
	int		j;

	new = ft_strnew(ft_strlen(label));
	i = 0;
	j = 0;
	while (label[i])
	{
		if (ft_strchr(LABEL_CHARS, label[i]))
		{
			new[j] = label[i];
			j++;
		}
		i++;
	}
	return (new);
}

static int	find_label(t_label *label, char *name, int line)
{
	char *clean;

	clean = clean_label(name);
	while (label && ft_strcmp(clean, label->name))
		label = label->next;
	free(clean);
	if (!label)
		error("Label not found", line);
	return (label->line);
}

static int	label_ahead(t_parts *start, int to_reach, int current)
{
	int	line;
	int	bytes;

	line = 0;
	bytes = 0;
	while (start && start->line != current)
		start = start->next;
	if (!start)
		error("Label not found", 0);
	while (start && start->line != to_reach)
	{
		if (start->line != line)
		{
			line = start->line;
			bytes += start->line_size;
		}
		start = start->next;
	}
	return (bytes);
}

static int	label_behind(t_parts *start, int to_reach, int current)
{
	int	line;
	int	bytes;

	line = 0;
	bytes = 0;
	while (start && start->line != to_reach)
		start = start->next;
	if (!start)
		error("Label not found", 0);
	while (start && start->line != current)
	{
		if (start->line != line)
		{
			line = start->line;
			bytes += start->line_size;
		}
		start = start->next;
	}
	bytes *= -1;
	return (bytes);
}

static int	calculate_lines(t_parts *start, int to_reach, int current)
{
	int	bytes;

	bytes = 0;
	if (current < to_reach)
		bytes = label_ahead(start, to_reach, current);
	else
		bytes = label_behind(start, to_reach, current);
	return (bytes);
}

void		write_dir(t_asm *data, t_parts *parts, int op)
{
	int		value;
	int		label_line;
	int		four_bytes;

	if (parts->value == MAX_INT)
	{
		label_line = find_label(data->labels, parts->name, parts->line);
		value = calculate_lines(data->parts, label_line, parts->line);
	}
	else
		value = parts->value;
	if ((op >= 0x01 && op <= 0x08) || op == 0x0d || op == 0x10)
	{
		if (!value)
		{
			write_null_bytes(4, data->wfd);
			return ;
		}
		four_bytes = swap_4_bytes(value);
		write(data->wfd, &four_bytes, 4);
	}
	else
		write_ind(value, data->wfd);
}
