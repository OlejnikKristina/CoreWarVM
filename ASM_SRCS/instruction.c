/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instruction.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 17:29:07 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/05 16:59:29 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

/*
**	@desc	- function removes SEPARATOR_CHAR (standard ',') from a string
**	@param	- char *s, string which might have SEPARATOR_CHAR
**	@return	- char *new, new string without SEPARATOR_CHAR
*/

char		*rm_comma(char *s, int line)
{
	char	*new;
	int		i;
	int		count;

	new = ft_strdup(s);
	i = 0;
	count = 0;
	while (new[i])
	{
		if (new[i] == SEPARATOR_CHAR)
		{
			count++;
			new[i] = '\0';
		}
		i++;
	}
	if (count > 1)
		error("Invalid syntax", line);
	return (new);
}

/*
**	@desc	- make new instruction object
**	@param	- int token, token of the new instruction/argument
**			- int line, line number of new object
**	@return	- new parts object
*/

t_parts		*make_instruction(int token, int line, char *s)
{
	t_parts	*new;

	new = malloc(sizeof(t_parts));
	new->token = token;
	if (new->token < 0)
		new->value = get_value(token, line, s);
	else
		new->value = 0;
	new->line = line;
	new->size = 0;
	new->line_size = 0;
	new->name = rm_comma(s, line);
	new->next = NULL;
	return (new);
}

/*
**	@desc	- function adds new instruction to linked list
**	@param	- t_asm *data, main struct
**			- t_parts *new, instruction object to be added
*/

void		add_instruction(t_asm *data, t_parts *new)
{
	t_parts	*curr;

	curr = data->parts;
	if (!curr)
	{
		data->parts = new;
		return ;
	}
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

/*
**	@desc	- function gets argument token from string
**	@param	- char *s, string to check
**	@return	- token corresponding to argument
*/

int			get_argument(char *s)
{
	if (s[0] == 'r')
		return (REG);
	else if (s[0] == DIRECT_CHAR)
		return (DIR);
	else
		return (IND);
}

/*
**	@desc	- function parse an instruction line
**	@param	- t_asm *data, main struct
**			- char **line, line split on whitespace
*/

void		parse_instruction(t_asm *data, char **line)
{
	t_parts	*new;
	int		i;

	i = 0;
	while (line[i])
	{
		new = make_instruction(get_token(line[i]), data->lines, line[i]);
		add_instruction(data, new);
		i++;
	}
}
