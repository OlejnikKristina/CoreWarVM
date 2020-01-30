/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_argc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 13:59:58 by krioliin       #+#    #+#                */
/*   Updated: 2020/01/17 20:35:48 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

bool	parse_error(void)
{
	int		fd;
	char	*line;

	fd = open("./utilities/usage_msg.txt", O_RDONLY);
	line = NULL;
	while (0 < get_next_line(fd, &line))
	{
		ft_printf("%s\n", line);
		if (line)
			ft_strdel(&line);
	}
	close(fd);
	return (true);
}

short	get_players_amnt(short players_amnt_init)
{
	static short players_amount;

	if (players_amount == 0)
	{
		players_amount = players_amnt_init;
		return (0);
	}
	return (players_amount);
}

/*
** Checks if any value of flag n is not bigger than amount of players
*/

bool	check_players_order(short players_order[MAX_PLAYERS],
		short players_amnt)
{
	short i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (players_amnt < players_order[i])
			return (false);
		i++;
	}
	get_players_amnt(players_amnt);
	return (true);
}

short	check_arg(int argc, char **params, int *num, t_flags *flags)
{
	short			is_falg;
	static short	players_amount;

	if ((is_falg = check_flag(argc, params, num, flags)))
	{
		if (argc - 1 == *num &&
		!check_players_order(flags->players_order, players_amount))
			return (-1);
		return (is_falg);
	}
	if (check_champ_file_name(params[*num]))
	{
		players_amount++;
		if ((argc - 1 == *num &&
		!check_players_order(flags->players_order, players_amount)) ||
		MAX_PLAYERS < players_amount)
			return (-1);
	}
	else
		return (-1);
	return (0);
}

/*
** Checks if input arguments (flags and player's files name) are correct.
** Sets flags into t_flag structure.
*/

bool	args_validation(int argc, char **params, t_flags *flags)
{
	int		num;

	num = 1;
	ft_bzero(flags, sizeof(t_flags *));
	flags->dump = 0;//IMPORTANT
	if (argc < 2)
		return (false);
	while (num < argc)
	{
		if (check_arg(argc, params, &num, flags) == -1)
			return (false);
		num++;
	}
	return (true);
}
