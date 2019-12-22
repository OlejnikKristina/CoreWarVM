/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_dir.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 19:44:42 by abumbier       #+#    #+#                */
/*   Updated: 2019/12/22 15:29:16 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

static int	find_label(t_label *label, char *name)
{
	char *clean;

	clean = clean_label(name);
	while (label && ft_strcmp(clean, label->name))	//check if strcmp stops the loop when equal
		label = label->next;
	if (!label)
		error("Label not found", line);//free and exit (specified label doesnt exist)
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
		ft_printf("current %d\tto_reach %d\n", current, to_reach);
		while (start && start->line != to_reach)
			start = start->next;
		if (!start)
			;//free and exit (shouldnt happen though)
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
		label_line = find_label(data->labels, parts->name, parts->line);
		value = calculate_lines(data->parts, label_line, parts->line); //subst value
		;
	}
	else
		value = parts->value;
	ft_printf("value: %d\n", value);
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
