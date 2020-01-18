/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_flags.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 17:39:09 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/15 15:13:15 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

short	is_hexdump(int argc, char **params, int *param_num, t_flags *flags)
{
	int	i;

	i = 0;
	if (!ft_strcmp((const char *)params[*param_num], "-hexdump"))
	{
		if ((*param_num == argc - 1 || flags->hexdump))
			return (-1);
		else
		{
			*param_num = *param_num + 1;
			while (params[*param_num][i])
			{
				if (!ft_isdigit(params[*param_num][i]))
					return (-1);
				i++;
			}
			flags->hexdump = ft_atoi(params[*param_num]);
			return (1);
		}
	}
	return (0);
}

short	is_dump(int argc, char **params, int *param_num, t_flags *flags)
{
	int	i;

	i = 0;
	if (!ft_strcmp((const char *)params[*param_num], "-dump"))
	{
		if ((*param_num == argc - 1 || flags->dump))
			return (-1);
		else
		{
			*param_num = *param_num + 1;
			while (params[*param_num][i])
			{
				if (!ft_isdigit(params[*param_num][i]))
					return (-1);
				i++;
			}
			flags->dump = ft_atoi(params[*param_num]);
			return (1);
		}
	}
	return (0);
}

void	add_n_flag(t_flags *flags, int from, int n)
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

short	check_n_pos(int n, short *players_order)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (n == players_order[i])
			return (0);
		i++;
	}
	return (1);
}

short	is_flag_n(int argc, char **params, int *num, t_flags *flags)
{
	int			n;
	static bool prev_was_nflag;

	if (!ft_strcmp((const char *)params[*num], "-n"))
	{
		if (*num == argc - 2)
			return (-1);
		*num = *num + 1;
		if (!params[*num])
			return (-1);
		n = ft_atoi(params[*num]);
		if (n < 1 || MAX_PLAYERS < n || !check_champion(params[*num + 1]))
			return (-1);
		if (!check_n_pos(n, flags->players_order))
			return (-1);
		if (prev_was_nflag == false)
			prev_was_nflag = true;
		add_n_flag(flags, 0, n);
		return (1);
	}
	if (!prev_was_nflag)
		add_n_flag(flags, 0, -1);
	prev_was_nflag = false;
	return (0);
}

short	check_flag(int argc, char **params, int *num, t_flags *flags)
{
	short		return_val;

	if ((return_val = is_hexdump(argc, params, num, flags)))
		return (return_val);
	else if ((return_val = is_dump(argc, params, num, flags)))
		return (return_val);
	else if (!ft_strcmp(params[*num], "-v"))
	{
		flags->v = true;
		return (1);
	}
	return_val = is_flag_n(argc, params, num, flags);
	return (return_val);
}
