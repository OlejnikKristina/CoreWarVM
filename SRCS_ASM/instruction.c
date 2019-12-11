/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instruction.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 17:29:07 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/11 13:46:50 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	@desc	- function gets the value of the argument token
**	@param	- int token, the token type
**			- int line, number of the line (in case of errors)
**			- char *s, the argument
**	@return	- int ret, the value of the token, -1 if error
*/

int			get_value(int token, int line, char *s)
{
	int		ret;

	ret = 0;
	if (token == REG)
	{
		ret = (int)ft_atoi(&s[1]);
		if (ret < 1 || ret > 99)
			error("Registry out of bounds", line);
		return (ret);
	}
	else if (token == DIR)
	{
		if (s[1] == LABEL_CHAR)
		{
			// ft_putendl(s);// get_label_value(s);
			return (0);
		}
		else if (ft_isdigit(s[1]))
		{
			ret = (int)ft_atoi(&s[1]);
			return (ret);
		}
	}
	else if (token == IND)
	{
		if (s[0] == LABEL_CHAR)
		{
			// ft_putendl(s);// get_label_value(s);
			return (0);
		}
		else if (ft_isdigit(s[0]))
		{
			ret = (int)ft_atoi(&s[1]);
			return (ret);
		}
	}
	error("Invalid token", line);
	return (-1);
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
**	@desc	- function decides if string is argument or instruction
**	@param	- char *s, string to be checked
**	@return	- returns correct token for the given string
*/

int			get_token(char *s)
{
	int		ret;

	ret = check_instruction(s);
	if (ret)
		return (ret);
	else
		return (get_argument(s));
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
