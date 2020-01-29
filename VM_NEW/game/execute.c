/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 17:55:13 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/29 15:21:48 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_arena.h"

/*
**	@desc	- function gets the size of op + args
**	@param	- t_byte opcode, operation code
**			- t_byte octal, octal
**			- int nb_arg, number of arguments
**	@return	- int size, total size
*/

static int	get_size(t_byte opcode, t_byte octal, int nb_arg)
{
	int shift;
	int i;
	int size;

	shift = 6;
	i = 0;
	size = 0;
	while (i < nb_arg)
	{
		if (((octal >> shift) & 3) == T_REG)
			size += 1;
		else if (((octal >> shift) & 3) == T_DIR)
			size += g_op_tab[opcode].dir_size;
		else if (((octal >> shift) & 3) == 3)
			size += 2;
		i++;
		shift -= 2;
	}
	return (size);
}

/*
**	@desc	- function checks if octal is valid
**	@param	- t_byte octal, octal to check
**			- int nb_arg, number of arguments
**	@return	- 1 on valid, 0 on invalid
*/

static int	valid_octal(t_byte octal, int nb_arg)
{
	int shift;

	if (octal & 3)
		return (0);
	if (nb_arg == 3)
		return (1);
	shift = nb_arg * 2;
	if (((octal << shift) & 0xff))
		return (0);
	return (1);
}

/*
**	@desc	- function checks operations with octals
**	@param	- t_vm *vm, main struct
**			- t_cursor *c, current cursor
*/

static void	check_octal(t_vm *vm, t_cursor *c)
{
	int		i;
	int		size;
	t_byte	octal;
	t_args	*args;

	octal = ARENA[get_index(c->pos, 1)];
	size = get_size(c->opcode, octal, g_op_tab[c->opcode].nb_arg) + 2;
	if (!valid_octal(octal, g_op_tab[c->opcode].nb_arg))
		return (mv_cursor(c, size));
	args = get_args(c, octal, ARENA);
	i = 0;
	while (i < g_op_tab[c->opcode].nb_arg)
	{
		if ((args[i].type == T_REG && (args[i].value < 1 || args[i].value > 16))
			|| !(args[i].type & g_op_tab[c->opcode].args[i]))
		{
			free(args);
			return (mv_cursor(c, size));
		}
		i++;
	}
	do_op(vm, c, args, size);
}

/*
**	@desc	- function executes 1 operation for 1 cursor
**	@param	- t_vm *vm, main struct
**			- t_cursor *c, cursor to execute
*/

static void	execute_op(t_vm *vm, t_cursor *c)
{
	int		size;
	t_args	*args;

	if (g_op_tab[c->opcode].octal)
		check_octal(vm, c);
	else
	{
		args = (t_args*)ft_memalloc(sizeof(t_args));
		args->size = g_op_tab[c->opcode].dir_size;
		size = args->size + 1;
		args->value = get_bytes(ARENA, get_index(c->pos, 1), args->size);
		args->type = T_DIR;
		do_op(vm, c, args, size);
	}
}

/*
**	@desc	- main function for executing operations
**	@param	- t_vm *vm, main struct
*/

void		execute(t_vm *vm)
{
	t_cursor	*c;

	c = CURSORS;
	while (c)
	{
		if (c->moved)
			opcode(ARENA[c->pos], c);
		if (c->wait_cycles > 0)
			c->wait_cycles--;
		if (!c->wait_cycles && (c->opcode >= 1 && c->opcode <= 16))
			execute_op(vm, c);
		else if (!c->wait_cycles)
			mv_cursor( c, 1);
		c = c->next;
	}
	if (FLAG->v)
		refresh_arena(vm);
}
