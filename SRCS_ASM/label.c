/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   label.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 14:31:21 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/10 19:15:37 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	@desc	- function checks if string is an instruction
**	@param	- char *s, string to check
**	@return	- returns > 0 if instruction
**			- returns 0 if not an instruction
*/

int			check_instruction(char *s)
{
	if (ft_strchr(s, LABEL_CHAR))
		return (0x00);
	if (ft_strequ(s, "live"))
		return (LIVE);
	else if (ft_strequ(s, "ld"))
		return (LD);
	else if (ft_strequ(s, "st"))
		return (ST);
	else if (ft_strequ(s, "add"))
		return (ADD);
	else if (ft_strequ(s, "sub"))
		return (SUB);
	else if (ft_strequ(s, "and"))
		return (AND);
	else if (ft_strequ(s, "or"))
		return (OR);
	else if (ft_strequ(s, "xor"))
		return (XOR);
	else if (ft_strequ(s, "zjmp"))
		return (ZJMP);
	else if (ft_strequ(s, "ldi"))
		return (LDI);
	else if (ft_strequ(s, "sti"))
		return (STI);
	else if (ft_strequ(s, "fork"))
		return (FORK);
	else if (ft_strequ(s, "lld"))
		return (LLD);
	else if (ft_strequ(s, "lldi"))
		return (LLDI);
	else if (ft_strequ(s, "lfork"))
		return (LFORK);
	else if (ft_strequ(s, "aff"))
		return (AFF);
	return (0x00);
}

/*
**	@desc	- fuction makes a new label object
**	@param	- char *s, name of the label
**			- int line, line number the label points to
*/

t_label		*make_label(char *s, int line)
{
	t_label	*new;

	new = (t_label*)malloc(sizeof(t_label));
	new->name = ft_strdup(s);
	new->line = line;
	new->next = NULL;
	return (new);
}

/*
**	@desc	- adds a label to the linked list of labels
**	@param	- t_asm *data, main struct
**			- t_label *new, label to be added
*/

void		add_label(t_asm *data, t_label *new)
{
	t_label	*curr;

	curr = data->labels;
	if (!curr)
	{
		data->labels = new;
		return ;
	}
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

/*
**	@desc	- function get the label variables if its not on the same line
**	@param	- t_asm *data, main struct
**			- char *name, name of the label
*/

void		get_next_label(t_asm *data, char *name)
{
	char	*s;
	char	**split;
	t_label	*new;

	split = NULL;
	while (get_line(data, data->rfd, &s, NULL))
	{
		if (s && !ft_strequ("", s))
		{
			split = ft_strsplit_ws(s);
			if (check_instruction(split[0]))
			{
				new = make_label(name, data->lines);
				add_label(data, new);
				parse_instruction(data, split);
			}
			else
				error("Invalid label", data->lines);
			break ;
		}
	}
	free_arr(&name, &split, 1);
}

/*
**	@desc	- function gets the label and all the variables
**	@param	- t_asm *data, main struct
**			- char **line, line read, split on whitespace
*/

void		get_label(t_asm *data, char **line)
{
	t_label		*new;
	char		**split;

	split = NULL;
	split = ft_strsplit(line[0], LABEL_CHAR);
	if (split[1])
	{
		ft_putendl(split[0]);
		new = make_label(split[0], data->lines);
		add_label(data, new);
		ft_strclr(line[0]);
		line[0] = ft_strdup(split[1]);
		parse_instruction(data, line);
	}
	else
		get_next_label(data, split[0]);
	free_arr(NULL, &split, 1);
}

/*
**	@desc	- parses the labels and the instructions
**	@param	- t_asm *data, main struct
**			- char *s, line read
*/

void		parse_label(t_asm *data, char *s)
{
	char	**split;

	data->wfd = 0;
	split = NULL;
	split = ft_strsplit_ws(s);
	if (check_instruction(split[0]))
		parse_instruction(data, split);
	else
	{
		if (!ft_strchr(split[0], LABEL_CHAR))
			error("Not a valid instruction", data->lines);
		else
			get_label(data, split);
	}
	free_arr(NULL, &split, 1);
}
