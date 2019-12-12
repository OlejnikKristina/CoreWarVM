/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 15:15:38 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/12 15:04:19 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	@desc	- validator function for LIVE
**	@param	- t_parts *head, start of the function/line
**	@return	- int t_dir, size of t_dir for that function
*/

int		handle_live(t_parts *head)
{
	t_parts	*curr;
	int		line;
	int		i;

	line = head->line;
	curr = head;
	i = 0;
	while (curr && curr->line == line)
	{
		if (i == 0 && curr->token != LIVE)
			error("Invalid argument", line);
		else if (i == 1 && curr->token != DIR)
			error("Invalid argument", line);
		curr = curr->next;
		i++;
	}
	if (i > 2)
		error("Too many arguments", line);
	return (4);
}

/*
**	@desc	- validator function for LD
**	@param	- t_parts *head, start of the function/line
**	@return	- int t_dir, size of t_dir for that function
*/

int		handle_ld(t_parts *head)
{
	t_parts	*curr;
	int		line;
	int		i;

	line = head->line;
	curr = head;
	i = 0;
	while (curr && curr->line == line)
	{
		if (i == 0 && curr->token != LD)
			error("Invalid argument", line);
		else if (i == 1 && (curr->token != DIR && curr->token != IND))
			error("Invalid argument", line);
		else if (i == 2 && (curr->token != REG))
			error("Invalid argument", line);
		curr = curr->next;
		i++;
	}
	if (i > 3)
		error("Too many arguments", line);
	return (4);
}

/*
**	@desc	- validator function for ST
**	@param	- t_parts *head, start of the function/line
**	@return	- int t_dir, size of t_dir for that function
*/

int		handle_st(t_parts *head)
{
	t_parts	*curr;
	int		line;
	int		i;

	line = head->line;
	curr = head;
	i = 0;
	while (curr && curr->line == line)
	{
		ft_printf("%s\t%d\n", curr->name, i);
		if (i == 0 && curr->token != ST)
			error("Invalid argument", line);
		else if (i == 1 && curr->token != REG)
			error("Invalid argument", line);
		else if (i == 2 && (curr->token != REG || curr->token != IND))
			error("Invalid argument", line);
		curr = curr->next;
		i++;
	}
	if (i > 3)
		error("Too many arguments", line);
	return (4);
}

/*
**	@desc	- validator function for ADD
**	@param	- t_parts *head, start of the function/line
**	@return	- int t_dir, size of t_dir for that function
*/

int		handle_add_sub(t_parts *head, int token)
{
	t_parts	*curr;
	int		line;
	int		i;

	line = head->line;
	curr = head;
	i = 0;
	while (curr && curr->line == line)
	{
		if (i == 0 && curr->token != token)
			error("Invalid argument", line);
		else if (i == 1 && curr->token != REG)
			error("Invalid argument", line);
		else if (i == 2 && curr->token != REG)
			error("Invalid argument", line);
		else if (i == 3 && curr->token != REG)
			error("Invalid argument", line);
		curr = curr->next;
		i++;
	}
	if (i > 4)
		error("Too many arguments", line);
	return (4);
}

/*
**	@desc	- controller function to check if the function calls are valid
**	@param	- t_parts *head, start of the function/line
**			- int token, tokenized operation code
**	@return	- int, size of t_dir
*/

int		check_line(t_parts *head, int token)
{
	if (token == LIVE)
		return (handle_live(head));
	else if (token == LD)
		return (handle_ld(head));
	else if (token == ST)
		return (handle_st(head));
	else if (token == ADD || token == SUB)
		return (handle_add_sub(head, token));
	// else if (token == AND || token == OR || token == XOR)
	// 	return (handle_and_or_xor(head, token));
	return (2);
}

/*
**	@desc	- function get the size of 1 line
**	@param	- t_parts *head, start of the operations on the line
**	@return	- t_parts *curr, the start of the next line
*/

t_parts	*get_size(t_parts *head)
{
	t_parts	*curr;
	int		line;
	int		t_dir;
	int		size;

	line = head->line;
	curr = head;
	size = 0;
	t_dir = check_line(curr, head->token);
	while (curr && curr->line == line)
	{
		if (curr->token > 0)
			size += 1;
		else if (curr->token == REG)
			size += 1;
		else if (curr->token == IND)
			size += 2;
		else if (curr->token == DIR)
			size += t_dir;
		curr = curr->next;
	}
	head->size = size;
	return (curr);
}

/*
**	@desc	- main controller function calculates how many bytes every line is
**	@param	- t_asm *data, main struct
*/

void	calc_line_byte(t_asm *data)
{
	t_parts	*curr;
	int		curr_line;

	curr = data->parts;
	curr_line = curr->line;
	while (curr)
	{
		if (curr->line == curr_line)
			curr = get_size(curr);
		else if (curr_line != curr->line)
			curr_line = curr->line;
	}
}