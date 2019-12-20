/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_dir.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 19:44:42 by abumbier       #+#    #+#                */
/*   Updated: 2019/12/20 16:08:35 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	find_label(t_label *label, char *name)
{
	if (!label || !name)
		return (-1);
	while (label && ft_strcmp(name, label->name))	//check if strcmp stops the loop when equal
		label = label->next;
	if (!label)
		;//free and exit (specified label doesnt exist)
	return (label->line);
}

static int	calculate_lines(t_parts *start, int to_reach, int current)
{
	int	line;
	int	bytes;

	line = 0;
	bytes = 0;
	if (current < to_reach)
	{
		// loop untill current(including) and count line lengths until to_reach(excluding)
		while (start && start->line != current)
			start = start->next;
		if (!start)
			;//free and exit (shouldnt happen though)
		while (start && start->line != to_reach)
		{
			if (start->line != line)
			{
				line = start->line;
				bytes += start->line_size;
			}
			start = start->next;
		}
	}
	else
	{
		// loop untill to_reach(including) and count line lengths untill current(excluding)
		// add - sign
		while (start && start->line != to_reach)
			start = start->next;
		if (!start)
			;//free and exit (shouldnt happen though)
		while (start && start->line != to_reach)
		{
			if (start->line != line)
			{
				line = start->line;
				bytes += start->line_size;
			}
			start = start->next;
		}
		bytes *= -1;
	}
	return (bytes);
}

void		write_dir(t_asm *data, t_parts *parts, int op)
{
	int		value;
	int		label_line;
	int		four_bytes;

	if (parts->value == MAX_INT)
	{
		label_line = find_label(data->labels, parts->name);
		value = calculate_lines(data->parts, label_line, parts->line); //subst value
		;
	}
	else
		value = parts->value;
	if ((op >= 0x01 && op <= 0x08) || op == 0x0d || op == 0x10)
	{
		four_bytes = swap_4_bytes(value);
		write(data->wfd, &four_bytes, 4);
	}
	else
		write_ind(value, data->wfd);
}
