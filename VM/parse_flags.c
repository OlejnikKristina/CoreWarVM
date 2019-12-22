/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_flags.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 17:39:09 by krioliin       #+#    #+#                */
/*   Updated: 2019/12/22 13:05:23 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

short	is_dump(int argc, char **params, int *param_num, t_flags *flags)
{
	if (!ft_strcmp((const char *)params[*param_num], "-dump"))
	{
		if ((*param_num == argc - 1 || flags->dump != -4242))
			return (-1);
		else
		{
			*param_num = *param_num + 1;
			flags->dump = ft_atoi(params[*param_num]);
			return (1);
		}
	}
	return (0);
}

void	add_n_falg(t_flags *flags, int from, int n)
{
	short		index;

	index = 0;
	while (index < MAX_PLAYERS)
	{
		if (flags->players_order[index] == from)
		{
			flags->players_order[index] = n;
			break ;
		}
		index++;
	}
}

short	is_flag_n(int argc, char **params, int *num, t_flags *flags)
{
	int		n;
	int		index;
	static bool prev_was_nflag;

	index = 0;
	if (!ft_strcmp((const char *)params[*num], "-n"))
	{
		if (*num == argc - 2)
			return (-1);
		*num = *num + 1;
		n = ft_atoi(params[*num]);
		if (n <= 0 || MAX_PLAYERS < n)
			return (-1);
		if (!check_champion(params[*num + 1]))
			return (-1);
		while (index < MAX_PLAYERS)
		{
			if (n == flags->players_order[index])
				return (-1);
			index++;
		}
		if (prev_was_nflag == false)
			prev_was_nflag = true;
		// else
		// 	prev_was_nflag = false;
		add_n_falg(flags, 0, n);
		return (1);
	}
	if (!prev_was_nflag)
		add_n_falg(flags, 0, -1);
	prev_was_nflag = false;
	return (0);
}

short	check_flag(int argc, char **params, int *num, t_flags *flags)
{
	short		return_val;

	if ((return_val = is_dump(argc, params, num, flags)))
		return (return_val);
	else if (!ft_strcmp(params[*num], "-v"))
	{
		flags->v = true;
		return (1);
	}
	return_val = is_flag_n(argc, params, num, flags);
	return (return_val);
}
